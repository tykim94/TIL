# 영상처리 9.4

- Sampling, transformations and filtering (샘플링, 변형, 필터링)
- Image enhancement (색, 대비, 선명도를 변형시켜 또렷하게 만듬)
- Image restoration (노이즈 제거, 이미지 흐림 보정, 흐릿한 안개 제거)
- Image compression (영상 압축: 영상의 질은 살리되, 용량 대폭 축소)
- Image in-painting (이미지 복원: 이미지의 파손, 낙서를 없애는 기술)
- Image registration (영상 정합: 휘어진 사진을 좌표를 사용하여 정면샷으로 변형)
- Video processing ()
- and many others ...

- - -

영상 처리와 관련된 분야들
- Machine Vision
- Computer Vision
- Robotics, Inspection, Photogrammetry
- M-d Signal processing
- Visual Perception
- Optical Engineering
- Computer Graphics
- Machine learning
- Artificial Intelligence

- - -

이미지란?

1. 밝기(또는 색)에 관련된 점(x,y)로 이루어진 함수 형식의 시각적 표현
2. 대부분의 이미지는 직사각형 위에 정의된다.

- - -

# Human visual system(HVS)

### Brightness adaptation(밝기 적응)

- HVS는 10의10승의 광도(light intensity, 빛의 강도) 범위에 적응할 수 있다.
- 주관적 밝기는 눈으로 들어온 빛의 강도의 로그함수곡선을 따른다. (Subjective brightness is a logarithmic function of the light intensity incident on the eye)

### Brightness discrimination

베버의 법칙(Weber's law) : 처음자극과 다음에 주어지는 자극의 세기간의 차이가 일정한 비율 이상이 되어야만 그 자극의 변화량을 감각기에서 느낄 수 있다는 법칙

일반적으로 눈은 베버비(Weber ration)가 1/120 ~ 1/100 이고, 미각은 1/6, 청각은 1/7으로 알려져있다.
>베버비: (자중자극 - 처음자극) / 처음자극

베버 비율의 작은 값은 강도의 작은 변화가 구별될 수 있다는 것을 의미한다. 이는 "좋은" 밝기 차이를 의미한다. **베버값이 작을수록 더 잘 구별한다.**

밝기는 어두운 조명에선 구분이 힘들다.
밝기는 밝은 조명에선 구분이 쉽다.

어두운 조명(low levels of illumination)은 rods(간상체, 간상세포)가 구별하고, 밝은 조명(high levels of illumination)은 cones(추상체, 원추세포)가 구별한다.

### 밝기를 인식하는 건 간단한 과정이 아니다

마하의 띠(Mach bands)나 동시 대비(Simultaneous contrast)를 두 눈으로 바라보면, 분명 점점 어두워지지만 경계선이 더 어두워 보이거나, 모두 같은 색인데 주변의 색으로 인해 다르게 보인다.

### Light and the Electromagnetic Spectrum (빛과 전자기파 스펙트럼)

인간이 인식할 수 있는 가시광선은 전자기파 스펙트럼으로 볼때 매우 협소한 부분을 차지하는 것을 확인할 수 있다.

```
파장의 길이
라디오파 > 마이크로파 > 적외선 > 가시광선 > 자외선 > X선 > 감마선
```

### Image sensor(영상센서)

영상센서는 빛에너지를 디지털 영상으로 바꾼다.

Sensing material is responsive to the particular type of energy being detected.
감지 물질은 감지되는 특정 유형의 에너지에 반응합니다.

Each sensor is proportional to the integral of the light energy projected onto the surface of the sensor.
각 센서는 센서 표면에 투영된 빛 에너지의 통합에 비례합니다.

- - -

# 영상처리 9.6

### Sampling and Quantization(샘플링과 양자화)

Sampling : 자연영상에서 일정한 간격으로 데이터를 뽑아내는 작업
1. 샘플링에 의해 추출된 각각의 데이터를 '픽셀(Pixel)'이라고 한다.
2. '화소'는 샘플링 수준(Sampling Rate)을 말한다. 즉 '500만 화소'인 사진은 픽셀이 500만 개인 데이터를 말한다.
3. '픽셀(Pixel)'의 배열로 이루어진 이미지를 '비트맵(Bitmap)'이라고 한다.

Quantization : 샘플링을 통해 뽑은 데이터에 숫자로 된 값을 할당하는 작업
1. 양자화 수준(Quantization Rate)에 따라 '256 Color','High Color', 'True Color'등 다양한 양자화가 있다.
2. 예를 하나 들자면, 대비가 있는 흑백 사진은 0(검), 1(흰) 두가지로 양자화한 사진이다.

샘플링 수준(Sampling Rate)은 이미지의 화질을 결정하고, 양자화 수준(Quantization Rate)은 색의 다양성을 결정한다.

### Qunatization(양자화)

Quantization is a lossy compression technique achieved by compressing a range of values to a single quantum value
정량화는 다양한 값을 단일 양자 값으로 압축하여 얻을 수 있는 손실 압축 기술입니다.

in the case of grey-scale images, given a required precision defined by L binary bits, one can represent 2L  different grey-levels
그레이 스케일 영상의 경우 L 이진 비트에 의해 정의된 필수 정밀도를 기준으로 2L의 서로 다른 그레이 레벨을 나타낼 수 있습니다.

For a L-bit pixel value, truncation to M most significant bits can be obtained as
L-bit 픽셀 값의 경우, M으로 절단할 수 있습니다.

𝑓 ̂[𝑛,𝑚]=𝑄_𝑀 {𝑓[𝑛,𝑚]}=2^(𝐿−𝑀)⋅⌊𝑓[𝑛,𝑚]⋅2^(𝑀−𝐿) ⌋

in the above quantizer, the output values are always smaller or equal to the input values
위의 정량기에서 출력 값은 항상 입력 값과 같거나 더 작습니다.


this quantizer can be improved as follows
이 정량기는 다음과 같이 개선될 수 있습니다.

𝑄_𝑀 {𝑓[𝑛,𝑚]}=2^(𝐿−𝑀)⋅⌊𝑓[𝑛,𝑚]⋅2^(𝑀−𝐿) ⌋ + 2^(𝐿−𝑀-1)

- - -

Qunatization의 종류

- Uniform/Non-Uniform Quantization
- Scalar/Vector Quantization

Vector Qunatization의 예시

16 colors : 대비가 강한 몇 안되는 색깔로 사진을 표현
16 million colors : 색이 다양하고 실제처럼 표현


Spatial Resolution

해상도가 낮을수록 픽셀이 눈에 보임을 알 수 있음. 1024X1024 같은 형식이 일반적

Gray-Level Resolution

해상도가 낮을수록 대비가 심함. 해상도가 낮으면 흑과 백밖에 없음

### Image Resizing

Image resizing (resampling)
이미지 크기 조정(재샘플링)

A method to increase (or decrease) the number of pixels in a digital image.
디지털 이미지에서 픽셀 수를 늘리거나 줄이는 방법입니다.

Some digital cameras use resizing to produce a larger image than the sensor captured or to create digital zoom.
일부 디지털 카메라는 크기를 조정하여 캡처한 센서보다 큰 이미지를 생성하거나 디지털 줌을 만듭니다.

이미지 크기 조정하는 두 가지 방법
- nearest neighbor
- bilinear interpolation
