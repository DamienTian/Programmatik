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

if isinstance(i, int):
    print("i is integer")
else:
    print("i is not integer")

w =0.8
if isinstance(w,float):
    print("w is not integer")
else:
    print("w is integer")

