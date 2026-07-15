import torch

w=torch.stack([torch.tensor([1,2,3,5,0]), torch.tensor([3,4,5,2,8]), torch.tensor([5,6,3,4,7])])
_,mn=torch.min(w,dim=0)
print(_,mn)


