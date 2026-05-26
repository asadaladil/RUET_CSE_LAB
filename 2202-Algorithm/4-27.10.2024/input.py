# from datetime import datetime
# def Quick_Sort(A):
#     if len(A)<=1:
#         return A
#     pivot=int(len(A)/2-1)
#     b=[]
#     c=[]
#     for i in range(len(A)):
#         if i==pivot:
#             continue
#         if A[i]<=A[pivot]:
#             b.append(A[i])
#         else:
#             c.append(A[i])
#     Sorted_B=Quick_Sort(b)
#     Sorted_C=Quick_Sort(c)
#     Sorted_A=[]
#     for i in range(len(Sorted_B)):
#         Sorted_A.append(Sorted_B[i])
#     Sorted_A.append(A[pivot])
#     for i in range(len(Sorted_C)):
#         Sorted_A.append(Sorted_C[i])
#     return Sorted_A


# def Merge_Sort(A):
#     if  len(A)<=1:
#         return A
#     m=int(len(A)/2)
#     left=[]
#     right=[]
#     for i in range (m):
#         left.append(A[i])
#     for i in range (m,len(A)):
#         right.append(A[i])
#     left=Merge_Sort(left)
#     right=Merge_Sort(right)
#     Sort_A=[]
#     id1=0 
#     id2=0
#     s=len(A)
#     for i in range(s):
#         if id1==len(left):
#             if id2<len(right):
#                 Sort_A.append(right[id2])
#                 id2+=1
#         elif id2==len(right):
#             if id1<len(left):
#                 Sort_A.append(left[id1])
#                 id1+=1
#         elif left[id1]<right[id2]:
#             Sort_A.append(left[id1])
#             id1+=1
#         else:
#             Sort_A.append(right[id2])
#             id2+=1
#     return Sort_A


# A=[]
# with open("./output/input.txt",mode="r") as file:
#     num=file.readlines()
#     for i in num:
#         A.append(int(i))
#     file.close()

# list=[1000,2500,5000,7500,10000,12500,15000,17500,20000]
# with open("./output/output.txt",mode="a") as data:
#     data.write("Time Counting:\n")
#     for i in list:
#         s=datetime.now()
#         B=A[0:i]
#         B=Merge_Sort(B)
#         f=datetime.now()
#         #print(B)
#         data.write(f"  {str(i)}\t\t")
#         data.write(f"\t\t    {(f-s).total_seconds()}s\t")
#         s=datetime.now()
#         C=A[0:i]
#         C=Quick_Sort(C)
#         f=datetime.now()
#         #print(C)
#         data.write(f"\t\t\t{(f-s).total_seconds()}s\n")
        

    
def Merge(left,right):
    Sort_A=[]
    id1=0 
    id2=0
    s=len(left)+len(right)
    for i in range(s):
        if id1==len(left):
            if id2<len(right):
                Sort_A.append(right[id2])
                id2+=1
        elif id2==len(right):
            if id1<len(left):
                Sort_A.append(left[id1])
                id1+=1
        elif left[id1]<right[id2]:
            Sort_A.append(left[id1])
            id1+=1
        else:
            Sort_A.append(right[id2])
            id2+=1
    return Sort_A

def Merge_Sort(l,h,arr):
    if(l==h):
        return [arr[l]]
    mid=int((l+h)/2)
    left=Merge_Sort(l,mid,arr)
    right=Merge_Sort(mid+1,h,arr)
    return Merge(left,right)


list=[10,4,8,25,6,1,9,5,7]
sorted_list=Merge_Sort(0,len(list)-1,list)
print(sorted_list)
