# Colab이란?

구글의 Colab은 기존의 Jupyter와 매우 흡사하다. 따로 개발툴을 깔지 않아도 크롬같은 인터넷 브라우저에서 실행이 가능하다. 또한 GPU까지 지원한다. 오픈소스를 활용한 프로젝트를 진행할 때 좋다.

- - -

# Python

**인터프리터 방식(<->컴파일러 방식)** 의 프로그래밍 언어이며, 문법이 매우 쉬워서 배우기가 쉽다. 따라서 파이선의 별명은 실행할 수 있는 수도코드(Executable pseudocode) 이다.

- - -

# 딥러닝이란?

- 머신러닝의 한 부분이다. 신경망(Neural Net)을 이용한 머신러닝이다.

> ***머신러닝(Machine Learning)***  : 머신러닝은 데이터를 기반으로 학습을 시켜 무언가를 예측하는 기법이며 통계학을 기반으로 추론(inference)를 함


**딥러닝방식(Deep Learning Methods)** 는 **딥 뉴럴 네트워크(Deep Neural Networks)** 라고도 하며 <u>*인간 두뇌의 뉴런 네트워크에서 아이디어를 얻어 개발되었습니다.*</u>

딥러닝에서 네트워크는 **되먹임 과정(Feedback process)** 을 통해 훈련이 됩니다.

```
인간이 의자 사진을 보고 의자로 인식할 때 오차율은 5%이다.

현재 딥러닝을 이용한 인식 결과 오차율은 2.3% ~ 3.0%로 인간보다 우수하다.
```

- - -

# TensorFlow란?

>딥러닝을 위해 구글이 제공하는 프레임워크. 누구나 쓸 수 있는 머신러닝 오픈소스 라이브러리

- - -

# Tensor란?

> Scalar -> Vector -> Matrix -> Tensor 순이다.

**Scalar** = 숫자 하나를 가리키는 용어. 우리가 아는 방향성이 없는 숫자

**Vector** = 숫자에 방향성이 더해짐. `ex) [1,2,4]`

**Matrix** = 2차원 수의 집합. 흔히 아는 배열 `ex) [[1,2],[3,4]]`

**Tensor** = 다차원 배열, Multidimensional Arrays `ex) RGB이미지 = 3차원배열`

- - -

# Numpy

Numerical Python의 줄임말이며 고성능 수치계산을 위해 만들어진 python package

```python
import numpy as np

# 배열 생성, 출력
a = np.array([1,2,3]) #rank 1(1차원) 배열 생성
print(type(a))        #배열a의 type 출력 "<class 'numpy.ndarray'>"
print(a.shape)        #배열a의 shape 출력 "(3,)"

b=np.array([[1,2,3],[2,2,2]]) #rank 2(2차원) 배열 생성
print(b.shape)                #배열b의 shape 출력 "(2, 3)"





# 배열 내부의 값 출력, 수정
print(a[0],a[1],a[2])       #배열a 내부의 값 출력 "1 2 3"
a[0] = 5                    #배열a 값 수정
print(b[0,0],b[0,1],b[1,0]) #배열b 내부의 값 출력 "1 2 2"




# 배열 생성
c = np.zeros((2,2))   #2행2열 배열 c 생성, 모두 0으로 채우기
print(c)              #[[0. 0.][0. 0.]]

d = np.ones((1,2))    #1행2열 배열 d 생성, 모두 1로 채우기
print(d)              #[[1. 1.]]

d2 = np.ones((2,1))   #2행1열 배열 d2 생성, 모두 1로 채우기
print(d2)             #[[1.][1.]]

d3 = np.full((2,2),7) #2행2열 배열 d3 생성, 모두 7로 채우기
print(d3)             #[[7. 7.][7. 7.]]

d4 = np.random.random((2,2))  #2행2열 배열 d4 생성, 임의의 값으로 채우기
print(d4)                     #2행2열에 각기 다른 4가지 값 채워짐




# Array Slicing
e = np.array([[1,2,3,4],[5,6,7,8],[9,10,11,12]])
f = e[:2,1:3]   #배열 e의 [0행~1행, 1열~2열] 값만 추출, (2,2) shape slicing
print(f)        #[[2,3][6,7]]




# element-wise : 엑셀의 sumproduct와 비슷한 개념
x = np.array([[1,2],[3,4]],dtype=np.float64)
y = np.array([[5,6],[7,8]],dtype=np.float64)
print(x+y)  #print(np.add(x,y))와 결과가 같다. [[6. 8.][10. 12.]]
print(x-y)  #[[-4. -4.][-4. -4.]]
print(x*y)  #[[5. 12.][21. 32.]]
```

- - -

# 내적(inner product)

벡터를 곱하는 방법으로 선형대수에서 많이 쓰인다. matmul과 같은 역할인 것 같지만 matmul은 행렬곱셈이고 dot은 내적으로 다르다. 1, 2차원 행렬의 곱에서는 값이 똑같이 나와 비교할 수 없지만 그 이상의 차원에서는 matmul과 dot의 값이 다르다고 한다.

```python

```
