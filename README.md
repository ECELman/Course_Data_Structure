# Course_Data_Structure

課堂作業與考試

# Homework 2

Homework set \#2

Data Structures

Deadline – 04/21/2017

Input: p2.in

Output: p2.out

Execution file: p2.exe

(Upload your homework to E-learning before 11:59pm. Please consult with your TA
(陳姿潔) for

any questions )

Problem description:

Given a sparse matrix A, transpose it by the following three methods:

(1) Using traditional 2-dimensional array representation

(2) Using the “Transpose” method in the textbook

(3) Using the “FastTranspose” method in the textbook

Input file description:

The first line reads as m\*n, where m and n are the number of rows and columns
of the matrix, respectively. The following n lines are these non-zero elements,
each line

corresponding to a data point in the matrix. E.g., a line may read as "4 0 3",
indicating A(4,0) = 3 (assuming the row and column indices start with 0).

Output file description:

The output shall consist of n+3lines where the first n lines should print out
the results of

the transpose (refer to the sample output below for an example). The (n+i)-th
line shall print

out the execution time of method i.

Sample Input:

5 6

0 0 1

0 2 1

1 1 2

2 0 4

2 2 3

Sample Output:

(0, 0, 1) becomes (0, 0, 1) in the transpose

(0, 2, 1) becomes (2, 0, 1) in the transpose

(1, 1, 2) becomes (1, 1, 2) in the transpose

(2, 0, 4) becomes (0, 2, 4) in the transpose

(2, 2, 3) becomes (2, 2, 3) in the transpose

0.03

0.02

0.01

Note:

For this homework, please use the input to generate a sparse matrix. Your code
should be able to read in the input file, and quit this reading process once it
reaches the EOF (end of file), and then start constructing the matrix.

In the homework, you are expected to work on the following tasks:

(1) Store all the elements using the 2-dimensional array representation. Then
transpose the

matrix.

(2) Store the non-zero elements using the triple format; then use "Transpose"
and

"FastTranspose" methods to do the matrix transposition.

# Homework 3

Homework set \#3

Data Structures

May/5/2017

Input: p3.in

Output: p3.out

Execution file: .exe

(Upload your homework before 11:59pm of May/5/2017. Please consult with your TA
for any

questions.

Problem description:

In the given input maze file (p3.in), 0's are available path and 1's are

blocked. Your homework is to use all the codes provided in the textbook,
including the template for the stack class and the path function to write your
C++ codes, in order for the rat to find the route out of the maze. It is
important that you fully understand each piece of the codes provided in the text
before writing your code. After completing the coding, write down what you learn
or any discussions from this exercise, as well.

Sample Output:

Print out the path found, if any, by marking the positions using "\*" for the
path in the

maze. For example, assuming you are given a 4× 5 maze whose entrance is (0, 0)
and exit is (3,4), then your output file may show the path as follows:

s \* \* 1 0

1 1 \* 1 0

0 1 \* 1 1

0 1 1 \* d

6

# Homework 4

HW4‧酋 長 與 航 海 士 的 打 賭

In pu t: s tdi n

O u tp u t: s td o u t

D eadl in e: 2 01 7/ 5/ 19

～ ～ ～ ～ ～ ～ ～ ～ ～ ～ ～ ～ ～ ～ ～ ～ ～ ～ ～ ～ ～ ～ ～ ～ ～ ～ ～
～ ～ ～ ～ ～ ～ ～

在 世 界 的 一 個 角 落 ， 某 個 食 人 部 族 、 他 們 吃 人 的 方 式 自 有 一 套
規 則 ： 只 吃 壞人 ， 因 此 他 們 會 先 將 捕 獲 的 生 人 透 過 古 老 的 密 術
鑑 定 善 良 與 否 、 最 後 只 將 壞 人 吃

掉 。 恰 巧 他 們 位 在 某 個 大 秘 寶 的 附 近 、 因 此 總 有 許 多 不 怕 死 的
人 來 成 為 他 們 的 食物 ， 像 是 探 險 家 、 考 古 學 家 、 海 賊 、 甚 至 是
海 軍 …這 天 、 戰 士 將 一 群 企 圖 取 得 秘 寶 的 傢 伙 抓 來 ， 交 由 酋 長
發 落 。

「 這 邊 旗 幟 是 三 個 骷 髏 的 海 賊 是 壞 的 ， 另 一 邊 戴 草 帽 骷 髏 的 海
賊 是 好 的 。 」

祭 司 這 麼 說 。

「 哦 ？ 」 酋 長 面 向 草 帽 骷 髏 海 賊 們 、 盯 著 其 中 一 個 標 緻 女 孩 說
：「 妳 是 團 裡的 航 海 士 ？ 」

她 犀 利 的 眼 神 對 答 道 ：「 是 的 ， 你 們 是 不 吃 好 人 的 吧 ？ 」

「 真 夠 直 接 ， 但 我 們 依 然 可 以 把 你 們 殺 死 而 不 吃 啊 ！ 哈 哈 哈 …
現 在 、 展 現 妳在 海 上 航 行 時 的 睿 智 吧 、 偉 大 的 航 海 士 。 」 酋 長
隨 著 輕 挑 的 語 調 、 緩 緩 站 起 來 ：

「 我 只 講 一 遍 、 妳 可 要 聽 清 楚 … 」。

1 . 俘 虜 中 好 人 K 個 、 壞 人 也 是 K 個 （ 一 共 2 K ）， 範 圍 [ 1 , 1 3 ]
。

2 . 好 人 與 壞 人 圍 成 一 個 圈 、 並 且 各 自 佔 據 一 半 。

3 . 殺 人 的 方 式 從 圓 圈 上 方 的 第 一 個 好 人 開 始 、 逆 時 針 數 N 個 ，
被 數 到 的第 N 個 就 得 死 ， 然 後 往 後 繼 續 數 第 N 個 殺 掉 ， 直 到 所 有 壞 人 死
光 、剩 下 好 人 為 止 ， 因 此 、 若 中 途 殺 到 好 人 就 失 敗 。

4 . K 值 為 酋 長 的 輸 入 值 ， 妳 要 負 責 在 1 5 秒 以 內 答 出 最 小 的 N 值
， 否 則就 會 先 殺 了 妳 那 吵 鬧 又 喜 歡 把 手 伸 來 縮 去 的 的 船 長 。

5 . 請 活 用 L i n k e d L i s t 概 念 ， 不 要 拘 泥 於 底 下 示 範 的 圖 。

# Homework 5

為 降 低 資 料 儲 存 的 空 間 或 增 加 資 料 傳 送 的 速 度，霍 夫 曼 編 碼 是
常 用 的 方 法。

假 設 有 一 個 字 元 集 ， 每 個 字 元 出 現 的 次 數 是 已 知 的 。 現 在 要 把
每 個 字 元 編 碼成 為 一 個 二 元 字 串 ( 例 如 把 ’ D ’ 編 碼 作 1 1 0 ) ， 採
用 的 編 碼 必 須 合 乎 以 下 條 件 ： 一 個字 元 的 編 碼 不 可 以 是 另 一 個
字 元 的 前 置 ( p r e f i x )，因 為 這 樣 在 解 讀 編 碼 時 就 可 以 不需 要
加 上「 一 個 編 碼 的 長 度 」就 能 解 讀 出 字 。 前 置 的 定 義 如 下 ： 若
一 個 字 串 s 1 為另 一 個 字 串 s 2 的 前 置 ， 則 從 s 2 的 最 後 一 個 字 元
開 始 ， 連 續 刪 除 一 定 數 量 的 字 元後 可 以 得 到 s 1 （ s 2 本 身 也 是 s
2 的 前 置 ）， 舉 例 而 言 : 如 果 字 元 ’A ’ 的 編 碼 是 1 1 0 ，而 字 元 ’ B
’ 的 編 碼 為 1 0 ， 則 ’ B ’ 的 編 碼 不 為 ’A ’ 編 碼 的 前 置 ； 如 果 字 元
’C ’ 的 編 碼 為1 1 0 0 ， 而 字 元 ’ D ’ 的 是 1 1 ， 則 ’ D ’ 的 編 碼 是 ’ C
’ 編 碼 的 前 置 。 以 下 的 編 碼 方 式 可 以 在符 合 這 個 條 件 下 給 出 最
經 濟 的 編 碼 。

編 碼 法 ， 請 參 考 老 師 投 影 片 「 C h a p 5 \_ f i n a l 」

1 . 如 以 下 所 述 建 立 一 棵 二 元 樹 ：

先 從 字 元 集 選 取 兩 個 出 現 次 數 最 低 的 字 元 作 合 併，合 併 後 以 一
個 全 新 的 虛 擬

字 元 取 代 這 兩 個 字 元 ， 新 字 元 的 頻 率 等 於 這 兩 個 就 字 元 頻 率 的
總 和 ， 並 令 這 兩 個

就 字 元 為 此 新 字 元 的 兩 個 子 樹 ， 左 右 不 拘 。 重 複 以 上 動 作 ， 直
至 字 元 集 剩 下 一 個

字 元 為 止 。

2 . 並 依 照 以 下 所 述 方 法 將 各 字 元 作 編 碼 。

由 上 一 步 驟 所 得 之 二 元 樹 ， 將 每 個 內 部 節 點 ( i n t e r n a l n o d
e ) 連 往 左 子 樹 的 邊

( e d g e ) 標 記 為 ’ 0 ’，連 往 右 子 樹 的 邊 標 記 為 ’ 1 ’。一 字 元 的 編
碼 即 為 從 樹 根 ( r o o t ) 至 此

字 元 ， 經 過 的 每 一 個 邊 的 標 記 所 成 之 字 串 （ 如 ： 在 此 ’ D ’ 編 碼
作 1 1 0 ）。

Homework 5

Input – p5.in, output – p5.out

Deadline – June/9/2017

本 次 作 業 目 標 在 對 一 串 文 字 ( A S C I I ) 進 行 編 碼

注 意 ：

1 . 將 受 編 碼 的 文 字 可 能 會 有 「 空 白 」、 但 不 會 有 「 換 行 」。

2 . I n p u t 中 字 元 出 現 次 數 之 後 沒 有 空 白 （ 如 ： D 6 ）、 介 於 出
現 次 數 與 編 碼文 字 中 間 為 一 單 純 「 換 行 」。

3 . O u t p u t 的 字 典 表 與 輸 出 編 碼 中 間 亦 為 單 純 空 行 。

4 . 有 檔 案 格 式 問 題 、 請 務 必 詢 問 助 教 或 是 知 道 的 人 ， 這 次 作
業 會 使 用 助教 的 解 碼 程 式 解 開 、 若 能 成 功 還 原 才 算 是 對 。

# Final Project

In this final project, you have to solve two major problems. And
分數配分比例如下:

Problem 1: 40%

Problem 2: 32%

Coding style: 28%

Each group has to compress the relevant files for this project and submit the

compressed file onto Elearning. Each group’s compressed file has to contain

(1) All the source codes

(2) The final report (no more than 20 pages in word file). In this report, you
have to

describe how you solve the problem and what results (可用截圖呈現) you obtain
for

each question. In the report, also make sure to describe each student’s role in
the final project.

In this project, when you have to find the maximum, minimum and median values,
the requirement is that you have to implement C++ classes for Heapsort and use
these classes for sorting (you have to write C++ classes, rather than just using
C language for this project) (實做出 heapsort 的 C++ classes 並用其做 sorting
為此專題之基本要求). Additionally, you may use other libraries to solve the
problem for comparison (可額外加分).

Problem 1: Single financial product problem -- daily prices of TWII (TSEC
weighted

index, 臺灣加權股價指數)

Dataset: “TWII_withRepeatedData.xlsx”

The dataset contains data from 5 columns as follows:

Column 1 Column 2 Column 3 Column 4 Column 5

Date Open_price High_price Low_price Close_price

Please write C++ codes for the following tasks:

Task (A): (共 20%, 底下(1)至(10)每小題各 2 分)

(1) Determine how many unique dates are in the dataset.

After removing the data from repeated dates, please use the closing price (i.e.,
the column for“Close_price”) to solve (2) – (9):

(2) Find the 10 smallest prices and which dates contain these smallest prices.

(3) Find the 10 largest prices and which dates contain these largest prices.

(4) Find the median price and its occurring date

(5) Compute the daily return for every day (except the first day). Then
determine what the maximum and minimum returns (return could be a negative
value) are and on which day(s) they occur.

Daily returns is defined as:

[(P(t+1)-P(t))/P(t)]\*100%, where t is date.

(6) Compute the intraday return for every day. Then determine what the maximum
and minimum returns (return could be a negative value) are and on which day(s)
they occur.

Intraday returns is defined as:

[(Close_price(t)-Open_price(t))/Open_price(t)]\*100%, where t is date.

(7) Make a plot of the closing price over time, in which the x-axis is the day
index and y-axis is the price.

(8) Make a plot of the daily return over time, in which the x-axis is the day
index and y-axis is the daily return.

(9) Make a plot of the intraday return over time, in which the x-axis is the day
index and y-axis is the intraday return.

(10) Find the maximum, minimum and median prices using all the 4 columns of
prices (i.e.,Open_price, High_price, Low_price and Close_price) and determine on
which date they occur.

Task (B): (共 20%, (1)至(10)每小題各 2 分)

For the same dataset used in Task (A), after removing the data from repeated
dates,

please generate a set of sampled data at the interval of every five days, then
do the

same tasks for (1)-(10) of Task (A).

\____________________________________________________________\_

Problem 2: Multiple financial products problem -- tick-based price data of
options

(選擇權)

Datasets:

“OptionsDaily_2017_05_15.csv”

“OptionsDaily_2017_05_16.csv”

“OptionsDaily_2017_05_17.csv”

“OptionsDaily_2017_05_18.csv”

“OptionsDaily_2017_05_19.csv”

Each dataset contains data from 9 columns as follows:

Column 1: 成交日期

Column 2: 商品代號

Column 3: 履約價格

Column 4: 到期月份(週別)

Column 5: 買賣權別

Column 6: 成交時間

Column 7: 成交價格

Column 8: 成交數量(B or S)

Column 9: 開盤集合競價

A financial product is defined by a unique combination of columns 2 to column 5.
I.e.,

if a value generated by combining the values of column 2, 3, 4, and 5 is unique,
then it defines a unique product. For example, in “OptionsDaily_2017_05_17.csv”,
the 3rd

row contains the following data:

Column 2 = CAO

Column 3 = 70

Column 4 = 201706

Column 5 = P

So the product “CAO_70_201706_P” is a unique options product.

Please write C++ codes by OOP coding style for the following tasks:

(1) Determine, totally, how many unique products exist in all these five
datasets. (3%)

(2) Determine if the product “TXO_1000_201706_P“ exists in these datasets. (3%)

(3) Determine if the product “TXO_9500_201706_C“ exists in these datasets. (3%)

(4) Determine if the product “GIO_5500_201706_C“ exists in these datasets. (3%)

(5) For “TXO_9900_201705_C“,

a. Find the 10 smallest prices and what time (determined by the unique
combination of Column 1 (成交日期) and Column 6 (成交時間)) these smallest
prices show up. (5%)

b. Find the 10 largest prices and what time these largest prices show up. (5%)

c. Find the median price of this product. (5%)

d. Compute the ticked-based return (except the first tick) using the values in
Column 7 (成交價格). Then determine what the maximum and minimum returns are and
when they occur. (5%)
