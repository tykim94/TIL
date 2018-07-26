# Exception Handling (예외처리)

나눗셈을 통해 몫과 나머지를 얻는 프로그램을 짰다고 가정하자.

```c++
int main(void)
{
  int 몫, 나머지
  cin >> num1 >> num2;

  몫 = num1 / num2;
  나머지 = num1 % num2;

  return 0;
}
```
만일 num2에 0이란 수를 넣었다고 하자. 우리가 원하는 답이 나올리 없다. 이럴때를 대비해 우리는 조건문을 중간에 넣어서 처리한다.
```c++
  if(num2 == 0)
  {
    cout << "num2에는 0이 들어올 수 없습니다. 프로그램 종료!" << endl;
    return 0;
  }
```

하지만 우리는 개발과정에서 수 많은 조건문과 반복문을 입력할텐데 눈에 띄게 예외처리를 알아볼 수 있을까? 따라서 우리는 예외처리를 위해 다른 구문을 사용하려한다.
- - -
## 예외처리 메커니즘
- try   : 예외를 발견한다.
- catch : 예외를 잡는다
- throw : 예외를 던진다.

예시로 확인하자
```c++
int main(void)
{
	int num1, num2;
	cout << "두 개의 숫자 입력: ";
	cin >> num1 >> num2;

	try
	{
		if (num2 == 0)
			throw num2;    //throw가 실행되면 아래 코드는 전부 무시한다.
		cout << "나눗셈의 몫: " << num1 / num2 << endl;
		cout << "나눗셈의 나머지: " << num1 % num2 << endl;
	}
	catch (int expn)
	{
		cout << "제수는 " << expn << "이 될 수 없습니다." << endl;
		cout << "프로그램을 다시 실행하세요." << endl;
	}
	cout << "end of main" << endl
	return 0;
}
```
try를 파서 if조건문 내에서 num2를 판단하고 예외발견시 throw로 던지고 catch로 예외라고 하여 반환된 expn으로 잘못됨을 알린다.
- - -
```c++
try
{
  //생략
  throw arr[i];
}
catch(char ch)
{ }
catch(int expn)
{ }
```
catch 구문은 두 개 이상 가질 수 있다. 위의 예제로 볼땐, 예외가 정수형일 수도 있고, 문자형일 수도 있으므로 catch 구문을 두개 가졌다.
- - -
또한 __전달되는 예외를 명시__ 할 수도 있다.
```c++
int MyFunc(int num) throw (int, char) //throw로 int형, 또는 char형만 반환 가능
{
  //생략
}
```
```c++
class DepositException //일반적인 클래스 생성, 예외를 위해 만들어진 클래스이다.
{
private:
  int depositMoney;
public:
  DepositException(int money) : depositMoney(money) { } //생성자
}


void Deposit(int money) throw (DepositException) //DepositException만 반환 가능
{
  //생략
  throw DepositException(money);
}
```
위의 두가지 예시를 보듯이, 일반적인 정수형(int)이나 문자형(char)을 throw로 보내기는 물론 클래스 형태로써 예외로 만들 수 있다.
- - -
__new 연산자에 의해서 발생하는 예외__
```c++
#include <iostream>
#include <new>
using namespace std;

int main(void)
{
	int num = 0;

	try
	{
		while (1)
		{
			num++;
			cout << num << "번째 할당 시도" << endl;
			new int[10000][10000];
		}
	}
	catch (bad_alloc &bad)
	{
		cout << bad.what() << endl;
		cout << "더 이상 할당 불가!" << endl;
	}
	return 0;
}
```
헤더파일 <new> 에는 bad_alloc 이라는 예외를 위한 클래스가 존재하는데 위의 코드에서 10000 * 10000 짜리 (무려 1억 * int(4byte) = 4억 바이트(400MB급) ) 배열을 무한히 반복문에서 동적할당한다. 물론 컴퓨터엔 물리적 한계가 있기에 몇 개 할당 못하고 할당 실패했음을 예외로 발생시킨다. 그 예외 bad_alloc을 catch구문으로 받는다.
- - -
# C++ 형 변환 (Casting)
```c++
#include <iostream>
using namespace std;

class Car //기초 클래스
{
    //생략
};
class Truck : public Car  //유도 클래스
{
  //생략
};

int main(void)
{
  Car * pcar1 = new Truck(80, 200);
  Truck * ptruck1 = (Truck * ) pcar1;  //pcar 형변환
}
```
이전에 우린 형 변환을 위의 식으로 했다. (int)3.55,  (double)3 이런 식으로 괄호 안에 바꾸길 원하는 형을 적었다.

하지만 위의 형 변환은 C언어때 써왔던 방식이다. 물론 C언어 방식을 쓰는 게 옳지 않다는 말은 아니다. 써도 되지만 C++에선 더 확실한 방법을 제시했다. 불가능한 형 변환일 땐 컴파일 에러를 내줘서 엉뚱한 값을 도출하는 것을 막을 수 있다.
- dynamic_cast
- static_cast
- const_cast
- reinterpret_cast

위의 4가지 연산자를 c++에서 제공한다.

```
*이러쿵저러쿵_cast<T>(expr)*  이런 형식으로 사용함

- < > 사이에 변환하고 싶은 자료형 입력. 단, 객체의 포인터 또는 참조형이 옴
- ( ) 사이에 변환 될 자료형 입력
```
- - -
### 1. dynamic_cast : 상속관계에서의 안전한 형 변환

>안전한 형 변환이란, 상속관계에 놓여 있는 클래스 사이에서 유도 클래스의 포인터 및 참조형 데이터를 기초 클래스의 포인터 및 참조형 데이터로 형 변환하는 경우를 말함.

```c++
//위와 같은 기초 클래스(Car), 유도 클래스(Truck) 이용함

int main(void)
{
    Car * pcar1 = new Truck(80, 200);
    Truck * ptruck1 = dynamic_cast<Truck* >(pcar1);  //컴파일 에러

    Car * pcar2 = new Car(120);
    Truck * ptruck2 = dynamic_cast<Truck* >(pcar2);  //컴파일 에러

    Truck * ptruck3 = new Truck(70, 150);
    Car * pcar3 = dynamic_cast<Car* >(ptruck3);      //컴파일 OK!!
}
```


2.
