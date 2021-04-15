import pymysql
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

# Question 1: SQL to barplot of Life Expectancy
pydb = pymysql.connect("localhost", "root", "MW$^cb77", "world")
dbcursor = pydb.cursor()

sql = "select LifeExpectancy, Name from country where Continent = 'Africa'"
dbcursor.execute(sql)
results = dbcursor.fetchall()
dbcursor.close()
results = results[1:10] #grab first 10, as too many countries to plot
df = pd.DataFrame(results, columns=['Life Expectancy', 'Country'])

sns.set(style="whitegrid")
ax = sns.barplot(x='Life Expectancy', y='Country', data=df)
plt.show()



# Question 2: xls to lineplot for date by item
fn = 'assign11-1-catering_sale_all.xls'
df2 = pd.read_excel(fn)
ax = sns.lineplot(x='sale date', y='chicken feet', data=df2)
plt.show()
