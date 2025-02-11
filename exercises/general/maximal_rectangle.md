 
Thuật toán:

- Tìm giá trị diagram lớn nhất tại vị trí i
    + Tìm index nhỏ hơn bên phải (rightsmaller)
    + Tìm index nhỏ hơn bên trái (leftsmaller)

- Giá trị max = rightsmaller - (leftsmaller + 1)* a[i]


Một số lưu ý:

stack lưu giá trị index

so sánh a[i] và a[st.top()]

Gán giá trị cho rightsmall[i] = n nếu st rỗng
Nếu st khác rỗng, thì lưu st.top

Ngược lại, gán giá trị cho left smaller = -1 nếu st rỗng
Nếu st khác rỗng, thì lưu st.top



#Để chuyển từ matrix sang diagram
tạo một matrix h
Nếu h = 0, a[i][i] khác 0, cộng vào
nếu a[i][j] == 0, h = 0
ex:
{{'1','0','1','0','0'},
{'1','0','1','1','1'},
{'1','1','1','1','1'},
{'1','0','0','1','0'}};

=> diagram
1 0 1 0 0
2 0 2 1 1
3 1 3 2 2
4 0 0 3 0
