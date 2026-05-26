class Sorting_Algorithm:
    def __init__(self):
        pass
    def Merge_Sort(self,A):
        if  len(A) <= 1:
            return A
        m=int(len(A)/2)
        B=[]
        C=[]
        for i in range (m):
            B.append(A[i])
        for i in range (m,len(A)):
            C.append(A[i])
        Sort_B=self.Merge_Sort(B)
        Sort_C=self.Merge_Sort(C)
        Sort_A=[]
        id1=0 
        id2=0
        s=len(A)
        for i in range(s):
            if id1==len(Sort_B):
                if id2<len(Sort_C):
                    Sort_A.append(Sort_C[id2])
                    id2+=1
            elif id2==len(Sort_C):
                if id1<len(Sort_B):
                    Sort_A.append(Sort_B[id1])
                    id1+=1
            elif Sort_B[id1]<Sort_C[id2]:
                Sort_A.append(Sort_B[id1])
                id1+=1
            else:
                Sort_A.append(Sort_C[id2])
                id2+=1
        return Sort_A
    
    def Quick_Sort(self,A):
        if len(A)<=1:
            return A
        pivot=int(len(A)/2-1)
        b=[]
        c=[]
        for i in range(len(A)):
            if i==pivot:
                continue
            if A[i]<=A[pivot]:
                b.append(A[i])
            else:
                c.append(A[i])
        Sorted_B=self.Quick_Sort(b)
        Sorted_C=self.Quick_Sort(c)
        Sorted_A=[]
        for i in range(len(Sorted_B)):
            Sorted_A.append(Sorted_B[i])
        Sorted_A.append(A[pivot])
        for i in range(len(Sorted_C)):
            Sorted_A.append(Sorted_C[i])
        return Sorted_A
    def Bubble_Sort(self,c):
        for j in range(0,len(c)):
            for k in range(0,len(c)-1):
                if c[k]>c[k+1]:
                    temp=c[k]
                    c[k]=c[k+1]
                    c[k+1]=temp
        return c

