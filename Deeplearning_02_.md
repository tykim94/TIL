# Regression(회귀)

주어진 데이터로 가설을 세운 후 그 가설을 이용하여 예측

>ex) 집 넓이를 x로 뒀을 때, 집 값을 y라 하면, 이를 이용하여 예측
- - -

# Linear Regression

ax + b 를 주어진 데이터에 맞게 정의하고 싶다. W1x + W2 라고도 한다.

H(x) = Wx + b 라고도 한다. W는 Weight(계수), b는 Bias(편향)을 말함. 여기 W와 b를 잘 만들어야지 새로운 데이터가 들어와도 예측을 잘할 수 있다. **상수 W와 b를 어떻게 튜닝 하느냐가 regression의 핵심이다.**

### ◆ Cost function

>H(x) - y

Cost 함수(Loss 함수)는 모델이 잘 학습되는지 조정할 수 있게 해준다. 가진 데이터와 현재 그래프 Wx + b 와의 차이를 Cost라고 부른다. 다른 말로는 오차(error) 라고 한다. 우리의 목표는 주어진 데이터셋과 그래프가 한 몸인 것처럼 보여야 합니다. 따라서 **오차인 Cost를 작게 만드는 것(Minimize cost)** 이 목표입니다. 물론 cost가 0에 가까워질수록 좋습니다.

Cost(W) = 시그마(min square error)  =  1/m * 시그마(   (Wx - y)^2   )

Cost 함수는 2차 곡선을 띄며 빗살무늬토기 같은 형태를 가집니다. 여기서 W의 값을 하나 가정하여 Cost(W)에서의 기울기를 구합니다. 그 기울기 값을 이용하여 W 값을 끊임없이 업데이트하여 0에 수렴하는 값에 근접했을 때 종료한다.

이때, 순수한 기울기 값만 이용하여 W를 업데이트하면 예상외로 너무 오랜 시간이 걸리거나 발산해서 오히려 정답과 멀어지는 현상이 일어난다. 이를 방지하기 위해 일종의 상수를 곱하는데 이 상수를 ***Learning rate*** 라고한다. 이 Learninig rate는 아직까지 구하는 공식이 없기 때문에 사람이 수작업으로 튜닝해줘야 한다.

>이렇게 기울기 0을 향해서 계속 달려가는 과정, 추정값을 찾아 찾아 가는 형식을 ***gradient descent*** 라고 한다.

- - -

# Convex?

>Convex function = 빗살무늬토기 같은 형태의 2차 함수
>
>Concave function = 빗살무늬토기를 엎어놓은 것 같이 생긴 2차 함수

이론상 Convex하게 cost 함수를 설계를 해야지 optimization이 잘 된다. Linear한 함수의 경우 거의 Convex하지만, 딥러닝의 경우 Non-Linear하고, 보통 Non convex하다. 그래서 Local Minima에 빠질 확률이 굉장히 높다.

딥러닝의 cost 함수는 많은 Local minima가 존재하여 학습이 어렵다. 그 중에 Global Minima를 찾아내는 것을 추구해야 한다.

- - -

# Logistic Regression

> Logistic = 모 아니면 도, 0 or 1, + or -
>
> Regression = fitting

Logistic Regression에서는 흔히 두 가지 함수를 주로 쓰는데 *sigmoid 함수* 와 *tanh(x) (하이퍼탄젠트) 함수* 이다.

`0 or 1` 인 데이터를 이용할 땐, sigmoid 함수를 사용한다.

`+ or -` 인 데이터를 이용할 땐, tanh(x) 함수를 사용한다.

공부한 시간을 기준으로 합격 여부(1, 0)를 예측하는 모델을 설계한다고 하자. 우린 sigmoid함수를 사용해야 한다는 것을 알 수 있다.

sigmoid 함수 = 1 / (  1+e^(-x)  ) = 1 / (  1+e^-(ax+b)  ) = 1 / (  1+e^-a(x+b)  )

흔히 1 / ( 1 + e^-(ax+b) ) 를 많이 사용한다.

- a상수를 키우면 y축에 더 가까이 붙으며 가팔라진다.

- b상수를 키우면 x축으로 평행 이동한다.

그래프를 그렸을 때, 중심점을 합격의 기준이라고 하며, logistic regression의 목표이다.

우린 여기서 a와 b를 계속 업데이트 하며 최적의 값을 찾으면 된다.

- - -

# Regression 과 Classification

Regression(회귀) = Continuous한 결과를 예측한다.

Classification(분류) = Discrete(분류, 클래스)한 결과를 예측한다. `ex)image classi.`

>Logistic Regression은 Discrete한 결과를 예측하므로 사실상 분류(Classification) 기법이지만 이름은 회귀다. 결과값의 range가 [0,1]으로 확률값으로 나온다.

- - -

# 학습 방식(Training)

- **지도학습(Supervised Learning)** = 학습중 문제에 대한 정답을 줌
- **비지도학습(Unsupervised Learning)** = 학습중 문제에 대한 정답을 주지 않음
- **강화학습(Reinforcement Learning)** = 현재 상태(State)에서 어떤 행동(Action)을 취하는 것이 최적인지 알아 내는 것
