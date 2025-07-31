import torch
import torch.nn as nn

class Model(nn.Module):
    def __init__(self):
        super().__init__()
        
        self.layers = nn.ModuleList([
            nn.Linear(1,10), 
            nn.ReLU(),
            nn.Linear(10,1)
            ])

        self.layers.append(nn.Linear(1, 5))
        self.layers.extend([nn.Linear(2, 8) for i in range(1, 3)])

    def forward(self, x):
        out = x
        for layer in self.layers:
            out = layer(out)
        return out
    
model = Model()
print(model)