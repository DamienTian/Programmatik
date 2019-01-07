# 佑佑的编程课 - Python
"""
第一节
print：打印（返还）结果终端
"""
# print("佑佑")
# print("ABCD")

"""
第二节
- 赋值：给一个物体一个值。值可以是一段文字（名字）也可以是数字。
- 加减乘除
"""
佑佑的身高 = 132 # 单位：厘米
学校的西服 = "蓝西服" # 赋值文字(string)的时候，要在文字两边加双引号

# 打印我们之前赋值的东西
# print(佑佑的全名)
# print(佑佑的全名)
# print(佑佑的全名)
# print(佑佑的身高)

哥哥的身高 = 184

# print(哥哥的身高 + 佑佑的身高)
计算 = 35-23
# print(计算)

"""
第三节：种类
- string (文本) 在后面加东西
- int (integer 整数)
- float (小数)
"""
佑佑的全名 = "田瀚佑"
# 加上小名：
佑佑的全名和小名 = 佑佑的全名 + "佑佑"
# print(type(佑佑的全名和小名))

# int
# i = 1

# if i >= 10:
#     print("你赢了")
# else:
#     print("你输了")

# float
# i = 3.1415926535
# # type: 返还这个东西是什么种类
# print(type(i))

i =8.8888   
# print(type(i))

"""
第四节：
条件逻辑：if，else
if 的意思：如果，else ：其他
if：当 （某件事情）发生 -》 我们怎么做
esle：如果其他情况发生 -》我们怎么做
"""
i = .1

if i >= 10:
    #print("你赢了")
    pass
else:
    #print("你输了")
    pass

# if isinstance(i, int):
#     print("i is integer")
# else:
#     print("i is not integer")

# 佑佑的作品
# w =0.8
# if isinstance(w,float) == True:
#     print("w is not integer")
# else:
#     print("w is integer")

"""
第五节：变量的种类
- Boolean(布尔值) - 对 or 错
    True - 对。  False - 错
- List(列表)
"""
# Boolean(布尔值)
# print(isinstance(w, float))
# print(isinstance(w, str))
# print(isinstance("w", str))

# List(列表)
list_1 = [6,5,9,0,8,7,1,2,3,6,3,7,4]
for i in list_1:
    pass

# 从 list 里挑一个数字
# print(list_1[7])  # 抽第八个数字，为什么写 ‘7’：
#                 # 在大部分编程语言里面：0 才是开头，0 是第一个数字
# # 从 list 里挑多个数字: 最后一位停止
# print(list_1[1:7])
# print(list_1[8:12])
# print(list_1[8:10000])
# print(list_1[9:11])            

"""
第六节：
元组（Tuple）:储存一系列的变量，但没法随意变更，且没有重复的变量
            用小括号包裹
字典（Dictionary）: 有一个 key (关键字) ，对应一个 value （值）
            用大括号包裹，有对应的 key 和 value
"""
t = (1,2,3) # 一个元组的范例
l = [1,2,3] # 一个列表的范例
l.append(4)
l.append(4)

tt = (1,1,2,2,3,3)

d = {
    "我": "佑佑",
    # key: "我"
    # value: "佑佑"
    "12": "34",
    "钥匙": "锁"
}

print(d["我"])
print(d["12"])

"""
第七节：
方法：(Function)
把你想要的执行命令输入到一个集合（方法）
"""

# 在 python 里面，方法是：
# 备注：def: define - 定义
# 方法（function) 可以是任何名字
def function(a, b):
    return a + b

a = 50000
b = 12446
print(function(a, b))