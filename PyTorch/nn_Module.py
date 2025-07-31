import torch
import torch.nn as nn
import torch.nn.functional as F

# 继承nn.Module定义自定义模型
class CustomCNN(nn.Module):
    def __init__(self, num_classes=10):
        # 初始化父类nn.Module
        super(CustomCNN, self).__init__()
        
        # 定义子模块（自动注册到nn.Module中）
        self.conv1 = nn.Conv2d(in_channels=3, out_channels=32, kernel_size=3, padding=1)
        self.pool = nn.MaxPool2d(kernel_size=2, stride=2)
        self.conv2 = nn.Conv2d(in_channels=32, out_channels=64, kernel_size=3, padding=1)
        self.fc1 = nn.Linear(64 * 8 * 8, 512)  # 假设输入图像为32x32
        self.fc2 = nn.Linear(512, num_classes)

    # 实现前向传播逻辑
    def forward(self, x):
        # x: 输入张量，形状为(batch_size, 3, 32, 32)
        x = self.pool(F.relu(self.conv1(x)))  # 卷积+激活+池化：(batch, 32, 16, 16)
        x = self.pool(F.relu(self.conv2(x)))  # 卷积+激活+池化：(batch, 64, 8, 8)
        x = x.view(-1, 64 * 8 * 8)  # 展平：(batch, 64*8*8)
        x = F.relu(self.fc1(x))  # 全连接+激活：(batch, 512)
        x = self.fc2(x)  # 输出层：(batch, num_classes)
        return x

# 实例化模型
model = CustomCNN(num_classes=10)

### model
print("\nmodel: ", model)  # 打印模型结构（由nn.Module自动实现）

### state_dict
print("\nmodel state dict keys: ", model.state_dict().keys())  # 打印模型参数字典key

### parameters
print("parameters......")
print(type(model.parameters()))
params = list(model.parameters())
print(params)
print(type(model.named_parameters()))
for name, params in model.named_parameters():
    print(name, params)

### buffers
print("\nbuffers......")
print(type(model.buffers()))
buffers = list(model.buffers())
print(buffers)
print(type(model.named_buffers()))
for name, buffers in model.named_buffers():
    print(name, buffers)

### children
print("\nchildren......")
print(type(model.children()))
children = list(model.children())
print(children)
print(type(model.children()))
for name, children in model.named_children():
    print(name, children)

### modules
print("\nmodules......")
print(type(model.modules()))
modules = list(model.modules())
print(modules)
print(type(model.named_modules()))
for name, modules in model.named_modules():
    print(name, modules)
