def longestPalindrome(s: str) -> str:
    lenth = len(s)
    table = [[0]*lenth for _ in range(lenth)]
    maxPosX = 0
    maxPosY = 0
    maxlen = 0
    for ijDif in range(lenth):
        for j in range(ijDif,lenth):
            i = j -ijDif
            if s[i] == s[j] and ( j-i<=1 or table[i+1][j-1] !=0 ): 
                table[i][j] = 1
                if ijDif > maxlen:
                    maxlen = ijDif
                    maxPosX = i
                    maxPosY = j
    return s[maxPosX:maxPosY+1]