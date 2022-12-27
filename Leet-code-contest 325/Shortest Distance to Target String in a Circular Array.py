class Solution(object):
    def closetTarget(self, words, target, start):
        """
        :type words: List[str]
        :type target: str
        :type startIndex: int
        :rtype: int
        """
        res = defaultdict(list)
        i = 0
        for ch in words:
            res[ch].append(i)
            i += 1
        if target not in res:
            return -1
        else:
            pos = res[target]
            ans = float('inf')
            for p in pos:
                i = (p - start) % len(words)
                j = (start - p) % len(words)
                ans = min(ans,i,j)
            return ans
