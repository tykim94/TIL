# 1. Introduction

- - -

## OS(Operating System) 란?
사용자 컴퓨터와 컴퓨터 하드웨어 사이에 작동하는 프로그램
 - 사용자와 컴퓨터 Hardware 사이의 인터페이스

OS의 목표
 - 유저의 프로그램을 실행하고 유저가 가진 문제의 해결을 쉽게 한다.
 - 컴퓨터 시스템을 편리하게 사용하도록 만든다.
 - 컴퓨터 Hardware를 효율적인 방법으로 사용한다.

 - - -
## 컴퓨터 시스템 구조
4가지 구성요소를 가진다.
- **Hardware** - 기본 컴퓨팅 리소스 제공
 - CPU, 메모리, 입/출력(I/O) 장치
- **Operating System(운영 체제)**
 - 다양한 applications 와 사용자 사이에서 하드웨어 사용을 통제하고 조정하라
 - 하드웨어를 가장 효율적으로 사용할 수 있게끔 해주는 시스템 프로그램이자, 사용자에게 얼마나 편리한 환경을 제공하냐의 시스템 프로그램이다.
- **Application programs(응용 프로그램)**
 - 워드프로세서, 컴파일러, 웹브라우저, DB 시스템, 비디오 게임
- **Users(사용자)**
 - 사람, 기계, 다른 컴퓨터들



 또는 우리는 컴퓨터 시스템을 **하드웨어, 소프트웨어 및 자료** 로 구성되어 있다고 볼 수도 있다.
 - - -

## 운영 시스템의 두가지 View Point

OS 역할의 두 가지 View Point : **User View, System View**
```
예전의 OS는 System View만 신경쓰는데도 바빴지만(리소스를 활용하는 것도 바쁨),
요즘의 OS는 User View도 많이 챙기고 있다.
```

- - -

## User View(사용자 관점)

#### ***목적 : Ease of Use(사용의 편리함)***
- 사용되는 인터페이스 뷰

- 컴퓨터를 사용하는데 __쉬워야 한다.__

- PC, 메인프레임(대형컴퓨터), 워크스테이션(특수한 분야에서 사용하는 고성능 컴퓨터), Handheld computers(스마트폰, 노트북 등 배터리를 사용하는 컴퓨터)를 사용하는데 얼마나 사용하기 편리한지에 관점을 둠

- 일부 컴퓨터는 임베디드 컴퓨터 및 자동차에 내장 된 컴퓨터와 같이 거의 또는 전혀 사용자 인터페이스가 필요가 없어서 사용자 관점이 존재하지 않거나 매우 작다.

```
★참고

윈도우의 아이콘 베이스는 애플이 특허권을 들고있다가 80년말,90년초에 특허권이 풀림.
곧바로 MICROSOFT가 아이콘 베이스 특허를 이용하여 윈도우를 만들게 된다.
```

- - -

## System View(시스템 관점)

#### ***목적 : Maximizing System Performance(시스템 성능 최대화)***
- 하드웨어와 가장 밀접하게 관련된 프로그램을

- 시스템의 성능을 최대화시키는 것이 목표

- 시스템 관점에서 OS는 Resource Allocator(자원 할당자)이다.
 - 모든 리소스를 관리(CPU 시간, 메모리 공간, 파일 저장 공간, 입/출력 장치)
 - 효율적이고 공정한 자원 사용에 대한 충돌하는 요청을 결정

- 시스템 관점에서 OS는 Control Program(제어 프로그램)이다.
 -  컴퓨터의 오류 및 부적절한 사용을 방지하기 위해 사용자 프로그램의 실행을 제어

- - -

## 운영시스템의 주요 기능 4가지

- Process Management
- Information Management
- Device Management
- Memory Management

- - -

## OS(운영시스템)의 정의
- No universally accepted definition : 이게 답이야! 라고 할 수 없다.
- ***하나의 소프트웨어의 모임인데 컴퓨터 HW 리소스를 관리하고 혹은 서비스를 위해서 제공하는 소프트웨어의 모임***
- 사용자가 "운영체제"를 주문했을 때 판매업자(Vendor)가 실어 보내는 모든 것이 고려되어야 한다. 다만 포함되는 기능은 시스템에 따라 크게 변한다.
- 보다 일반적인 정의로 ***운영체제는 컴퓨터에서 항상 수행되는 프로그램(일반적으로 Kernel이라 불린다)이며, 다른 모든 것은 시스템 프로그램(OS와 함께 제공됨) 또는 응용 프로그램이다.***

```
탐색기를 더블클릭 했을 때, 열고 띄워주는 것이 OS(정확히는 OS의 커널)이다.
```

>컴퓨터나 스마트폰 전원을 딱 켰을 때, 이 띄우는 놈을 우리는 bootstrap program 이라고 한다. 물론 OS의 일부이긴 한데, 일반적으로 펌웨어(firmware)로 알려져있다. ROM(Read-Only Memory) 이나 EEPROM에 아예 박혀져있다. 이것은 CPU 레지스터로부터, 장치 제어기, 메모리 내용 등을 포함한 시스템의 모든 면을 초기화한 후, Kernel을 띄우기 시작한다.

- - -

## 컴퓨터 시스템의 구조

컴퓨터를 구성하는 5대 구성요소

- 입력장치 : 키보드, 마우스, 마이크, 스캐너
- 출력장치 : 모니터, 스피커, 프린터
- 기억장치 : 중앙처리장치(CPU), 주기억장치(RAM), 보조기억장치(HDD, SSD)
- 연산장치 : CPU
- 제어장치 : CPU
```
이러한 컴퓨터 기본 구조는 1940년대에 나오기 시작함.
비공식적인 컴퓨터 구조 구상은 바비지의 아내
```

- - -

# Computer-System Operation

<u>***Concurrently : 동시성***</u>
>ex) 인쇄를 하면서 워드를 처리한다

요즘 우리는 작업관리자를 켜서 강제로 프로세스를 죽일 수 있다. 이런 행위를 <u>***Interrupt***</u>라고 한다.일종의 통신방식(Communication Method)으로 <u>Interrupt는 device와 OS간의 통신을 위한 수단이다.</u>

따라서 OS는 무조건 ```Interrupt driven system program```이다.

- - -

# Interrupt

Interrupt가 CPU에서 발생하면?

0. I/O device에서 CPU로 명령을 보냄.

1. 실행중인 작업을 중단하고 즉시 실행을 고정 위치로 전송.(Interrupt신호와 CPU의 Interrupt Processing 사이의 생기는 딜레이를 **real-time** 이라고 한다)

2. 고정 된 위치는 일반적으로 인터럽트에 대한 서비스 루틴이 있는 시작 주소를 포함.

3. 인터럽트 서비스 루틴이 실행. 완료시,

4. CPU는 인터럽트 계산을 재개

- - -

# Storage Structure(스토리지 구조)

무엇인가를 실행시키고 싶으면, 메모리에 올리는 것이 필수이다.

- Main memory - CPU가 직접 액세스 할 수 있는 대용량 저장 매체
>ex) ram

- Secondary storage - 대규모 비 휘발성 저장 용량을 제공하는 메인 메모리의 확장
>ex) 하드디스크

- Magnetic disk - 경질 금속 또는 유리 플래터는 자기 기록 물질로 덮여있음
>옛날에 사용함

- Solid-state disk - Magnetic disk보다 빠름. **Volatile(휘발성의)**

- - -

# Storage Hierarchy(스토리지 계층)

4가지 특징으로 나눈다.
- Speed(속도)
- Cost(가격)
- Volatility(휘발성)
- Size(크기)

***Caching*** - 정보를 굉장히 빠르게 스토리지에 복사. 메인 메모리는 second storage(HDD)를 위한 캐시로 간주.


```
register(레지스터) - 가장 빠름, 제일 비쌈
｜
cache
｜
main memory
｜
ssd
｜
magnetic disk
｜
optical disk
｜
magnetic tapes
```

# Peripheral Devices(주변 장치)

주변장치를 사용하기위해선 드라이버 장치가 필요하다.

keyboard를 사용하기 위해선 keyboard Driver가 필요하듯 말이다.

# Harddisk

CPU에서 바라봤을 때 하드디스크는 스토리지일 뿐이다.

메인 프로세스가 바라봤을 때, 하드디스크 또한 입출력장치일 뿐이다.

# 현대의 컴퓨터

기본적으로 폰 노이만(Von Neumann)이 구상한 구조를 따른다.

- - -

# 컴퓨터 시스템 구조(Architecture)

- Single Process System = 하나의 CPU를 가짐
- Multi Process System = 여러개의 CPU를 가짐
>ex1) 하나의 코어안에 두 개 이상의 CPU
>
>ex2) 하나의 CPU안에 코어가 두 개, 4개, 8개 있는 경우
>
>ex3) 하나의 칩안에 CPU가 두 개 이상, 그 CPU에 코어가 4개씩
>
>이러한 복잡한 모든 상황을 Multi Process System 이라 한다.

- Cluster System = 위의 개념을 네트워크로 묶어 놓은 시스템

대부분의 시스템은 single general-purpose processor 를 들고있다. 여기도 프로세스는 하나다. 안에 듀얼코어로 묶어놨을 뿐이다.

- - -

# 멀티프로세서

OS 관점에서는 기본적으로 필요하다. 왜냐하면 둘 이상으로 실행시키기 위해서 필요하다. 하나의 프로그램안에선 하나의 흐름만을 가진다. 흐름이란 코드의 진행을 말한다. 하지만 프로그램이 점차 복잡해지면서 하나의 프로그램안에서
