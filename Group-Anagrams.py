class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagrams = defaultdict(list)
    
        for word in strs:
            key = ''.join(sorted(word))  # sort the word to form a key
            anagrams[key].append(word)   # group words with the same key
        
        return list(anagrams.values())