print("\n创建空字典:")
emptyDict = {} # 使用大括号 {} 来创建空字典
emptyDict = dict() # 使用内建函数来创建空字典

print(emptyDict)
print("Length:", len(emptyDict))
print(type(emptyDict))
print(str(emptyDict))

print("\n访问字典value:")
tinydict = {'Name': 'Runoob', 'Age': 7, 'Class': 'First'}

print ("tinydict['Name']: ", tinydict['Name'])
print ("tinydict['Age']: ", tinydict['Age'])

print("\n修改字典:")
tinydict = {'Name': 'Runoob', 'Age': 7, 'Class': 'First'}
tinydict['Age'] = 8               # 更新 Age
tinydict['School'] = "菜鸟教程"  # 添加信息
 
print ("tinydict['Age']: ", tinydict['Age'])
print ("tinydict['School']: ", tinydict['School'])

print("\n删除字典key:")
tinydict = {'Name': 'Runoob', 'Age': 7, 'Class': 'First'}
 
del tinydict['Name'] # 删除键 'Name'
 
print ("tinydict['Age']: ", tinydict['Age'])
try:
    print ("tinydict['Name']: ", tinydict['Name'])
except KeyError:
    ...
