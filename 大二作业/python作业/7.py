# python作业：利用 Numpy 随机生成某工厂每天的产量数据。
#汇总每月总产量，并使用 bar () 方法来绘制柱形图。再使用 hist () 方法来绘制直方图，进行统计分析。
import numpy as np
import matplotlib.pyplot as plt

monthdays=[31,28,31,30,31,30,31,31,30,31,30,31]
month_sum=[] #每月总常量
daily=[] #每天常量
months=np.arange(1,13)

#数据部分
for days in monthdays:
    # 假设每天常量在200-1200之间
    daily_output = np.random.randint(200, 1201, size=days)
    #生成一个月每天的常量随机数
    month_sum.append(daily_output.sum())
    daily.extend(daily_output)

#print("每月总产量：", month_sum)
#print("全年天数：", len(daily))

#图表
plt.bar(months,month_sum) #每月总和
plt.xlabel("Month")
plt.ylabel("Total")
plt.title("Monthly Production")
plt.xticks(months) #让12个月都被呈现

plt.figure()#新建图片
plt.hist(daily, bins=10, edgecolor="black")
plt.xlabel("Daily Output")
plt.ylabel("Frequency")
plt.title("Distribution of Daily Production")

plt.show()
