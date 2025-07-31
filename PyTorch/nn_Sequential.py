import torch.nn as nn
from collections import OrderedDict

print("默认构造方式：")
model = nn.Sequential(
          nn.Conv2d(1, 20, 5),
          nn.ReLU(),
          nn.Conv2d(20, 64, 5),
          nn.ReLU()
        )
print(model)
print('\n')

print("构造时，给每一层添加名称：")
model = nn.Sequential(OrderedDict([
          ('conv1', nn.Conv2d(1, 20, 5)),
          ('relu1', nn.ReLU()),
          ('conv2', nn.Conv2d(20, 64, 5)),
          ('relu2', nn.ReLU())
        ]))
print(model)
print('\n')

print("通过add_module()构造：")
model = nn.Sequential()
model.add_module("conv1", nn.Conv2d(1, 20, 5))
model.add_module('relu1', nn.ReLU())
model.add_module('conv2', nn.Conv2d(20, 64, 5))
model.add_module('relu2', nn.ReLU())
print(model)
print('\n')

print("nn.Sequential()只支持通过索引获取第几个层：")
print('0', model[0]) 
print('1', model[1]) 
print('2', model[2]) 
print('3', model[3]) 

print("利用nn.Sequential构造block：")
class Model(nn.Module):
    def __init__(self):
        super().__init__()
        self.block = nn.Sequential(nn.Conv2d(1,20,5),
                                    nn.ReLU(),
                                    nn.Conv2d(20,64,5),
                                    nn.ReLU())
    def forward(self, x):
        x = self.block(x)
        return x
 
model = Model()
print(model)
print('\n')