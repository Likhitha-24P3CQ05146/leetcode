class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        d2={}
        for i in p:
            if i in d2:
                d2[i]+=1
            else:
                d2[i]=1
        print(d2)
        #Apply sliding window on s
        left=0
        d1={}
        ans=[]
        k=len(p)
        for right in range(len(s)):
            d1[s[right]]=d1.get(s[right],0)+1
            #windows_size=k
            if right>=len(p)-1:
                if d1==d2:
                    ans.append(left)
                d1[s[left]]-=1
                if d1[s[left]]==0:
                    d1.pop(s[left])
                left+=1
        return ans
                     
