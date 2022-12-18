class Solution:
    def similarPairs(self, words: List[str]) -> int:
        count=0
        n=len(words)
        for i in range(n-1):
            for j in range(i+1,n):
                if(set(list(words[i]))==set(list(words[j]))):
                    count+=1
        return count
        
