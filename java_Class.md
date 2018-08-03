# java_Class
- - -
- - -
```java
public class Car{

   }
```
- Car.java 파일이다.
- 저장을 하면 이클립스는 컴파일하여  디스크에 Car이라는 클래스 생성한다.
- __자동차 클래스가 생성되었다고 해서 자동차가 만들어 진것은 아니다.__

## Car객체 생성하기(자동차 만들기)
```java
public class CarExam{
    public static void main(String args[]){
        Car c1 = new Car();
        Car c2 = new Car();
    }
}
```
- new 연산자는 new연산자 뒤에 나오는 생성자를 이용하여 메모리에 객체를 만들라는 명령.
- 메모리에 만들어진 객체를 인스턴스(instance)라고도 한다.
- 이렇게 만들어진 객체를 참조하는 변수가 c1, c2 이다.
- 위의 코드가 실행되면 Car라는 객체가 2개가 만들어지고 각각의 객체를 참조하는 c1과 c2변수가 선언됩니다.
- - -
# 참조 타입
## 참조형 타입은 기본형 타입을 제외한 모든 타입이다.
- 참조형 변수
 - String str = new String("hello");
  - str 변수 앞에 기본형 타입이 아닌 String클래스가 적혀있다.
  - 이퀄(=)뒤에는 new다음에 생성자라는 것이 있다.
  - new 라는 키워드는 클래스를 메모리에 올려준다. 이렇게 메모리에 올라간 클래스를 인스턴스라고 말한다.


```java
    String str1 = "hello";
    //hello라는 문자열이 상수들이 저장되는 영역에 저장 됨. 상수 = 변하지 않는 값
    String str2 = "hello";
    //우선 hello라는 것이 상수들이 저장되는 영역을 우선 살펴봄. 있으면, 새로 만들지
    // 않고 이 hello를 가리킴. 따라서 이 str1 과 str2는 같은 인스턴스를 가리키고있다.
    //같은 인스턴스를 참조하고있다!


    String str3 = new String("hello");
    //위와는 다르게 new를 사용함 -> 상수영역에 있는 것을 참조하지 않는다.
    //새로 인스턴스를 heap영역에 만들게 된다! 따라서 str3과 str4는 각각 연결한다.
    String str4 = new String("hello");

    str1 == str2 는 true 이다.
    str3 == str4 는 false 이다.

    System.out.println(str1.substring(3));//인덱스 3번부터 출력해
    //String 클래스가 가지고있는 메서드들을 볼 수 있다.(.을 찍으면 보임)
    //substring은 그 일종임
```
- - -
## 필드(field)선언

```java
public class Car{
    String name;    
    int number;
}
```
두 개의 필드(name, number)를 가진 Car클래스 선언

```java
  Car c1 = new Car();
  Car c2 = new Car();
  //Car라는 인스턴스가 메모리에 2개 만들어 진다.
  //객체별로 name과 number라는 속성을 가진다.
```
Car클래스를 인스턴스화 하기
- - -
## 메소드
객체지향 언어라는 의미는 하나의 사물을 하나의 클래스로 설명하는 언어임.

사물에 대한 설명은 __물체의 상태__와 __물체의 행동__ 으로 나뉜다.

상태가 field라면 행동은 method가 된다.
메소드는 수학의 함수와 비슷함. 입력값을 받아서 결과값을 냄.

입력값 : 매개변수(parameter), 인자(argument)
결과값 : 리턴값

매개변수: 전달된 인자를 받아들이는 변수를 의미
인자 : 어떤 함수를 호출할 때 전달되는 값 자체를 의미
- - -
## 메소드 선언
```java
//	메서드란 클래스가 가지고 있는 기능을 의미
//	따라서 내부에 선언됨
//	public 리턴타입 메소드명 (매개변수){구현}
//	(리턴타입 : 메서드가 실행된후에 결과값을 되돌려주는 부분을 의미


//1. 입력X 출력X
	public void method1() {
		System.out.println("m1이 실행됨.. ");
	}
    //void : return 타입이 없다를 의미

	//2. 입력 1개, 출력X
	public void method2(int x) {
		System.out.println(x + "를 이용한 m2");
	}

	//3. 입력 X, 출력 O
	public int  method3() {
		System.out.println("m3 실행");
		return 10;
	}

	//4. 입력 2개, 출력 X
	public void method4(int x, int y) {
		System.out.println(x + y + "method4 실행");
	}

	//5. 입력 1개, 출력 O
	public int method5(int y) {
		System.out.println(y + "이용한 m5 실행");
		return y * 2;
	}
```
- - -

## 메소드 사용

```java
 MyClass myclass = new MyClass();
 		myclass.method1();
 		myclass.method2(10);
```
- - -
## 변수의 Scope와 static
프로그램상에서 사용되는 변수들은 사용 가능한 범위를 가진다. 그 범위를 변수의 스코프(scope)라고 한다. 이런 변수의 범위에 대해서 자세히 알아보자.

변수가 선언된 블럭( {...} ) 이 그 사용 범위인 것이 일반적이다.

```java
public class VariableScopeExam {

	int globalScope = 10;
	static int staticVal = 7; // static한 field선언

  public void scopeTest(int value) {
		int localScope = 20;
    System.out.println(globalScope);  //블럭 안 전역 변수로 존재
		System.out.println(localScope);   //블럭 안 로컬 변수로 존재
		System.out.println(value);        //블럭 안 매개 변수로 존재
		System.out.println(staticVal);    //블럭 안 스태틱 변수로 존재
  }

  public void scopeTest2(int value2) {
  System.out.println(globalScope);
  //System.out.println(localScope);     //컴파일 에러(블럭 벗어남)
  //System.out.println(value);          //컴파일 에러(블럭 벗어남)
}

  public static void main(String[] args) {
  //System.out.println(globalScope);//컴파일 에러(static 때문)
  //System.out.println(localScope); //컴파일 에러(블럭 벗어남 & static때문)
  //System.out.println(value);      //컴파일 에러(블럭 벗어남 & static때문)
  System.out.println(staticVal);    //static한 메서드에선 static한 변수만 가능
}
```
우리가 흔히 메서드를 사용할 때 어떻게 하는가? new를 사용하여 메모리에 우선 클래스를 인스턴스화 해야한다. 해당 클래스를 new를 통해 인스턴스화 한 후 메서드를 불렀다.
```java
VariableScopeExam v1 = new VariableScopeExam(); //이렇게 클래스 인스턴스화 해야만,
v1.scopeTest2(30);      //그제서야 scopeTest2라는 메서드 생성 가능
```

우리는 하나 깨달아야 하는 것이 있다. 우리는 아무 생각 없이 main을 썼지만 자세히 보면 ```public static void main(String[] args)```라고 적혀있는 것을 확인할 수 있다. main도 엄연한 클래스 내 메서드 중 하나였다는 것!

하지만 우리가 ```v1.main();```이렇게 불러본 적이 있는가? 단언컨데 단 한번도 이렇게 메인 메서드를 불러본 적이 없다.

static을 붙여주기만 하면 마법처럼 static한 매서드(예를 들면, main메서드) 또는 static한 필드(예를 들면, 위 코드의 staticVal)를 클래스가 인스턴스화 되지 않더라도 사용이 가능하다.

<u>이렇게 static한 메서드는 객체를 생성하지 않아도 사용할 수 있기 때문에 static한 메서드 내에서 static하지 않은 필드 (여기서는 staticVal 말함)는 사용할 수 없습니다.</u>

그렇다면, static한 메서드(예를 들면, main 메서드)에서는 static하지 않은 필드들을 어떻게 사용할까? 이 질문은 매우 우숩다. 우리가 이때까지 하던 것 아닌가?
```java
public static void main(String[] args)
{
 VariableScopeExam v1 = new VariableScopeExam(); //이렇게 클래스 인스턴스화 해고,
 v1.globalScope = 20;  //필드를 꺼내 쓸 수 있고,
 System.out.println(v1.globalScope); //출력할 수도 있다.
}
```
static한 필드는 인스턴스 생성 시에 만들어지는 것이 아니고, 클래스를 저장할 때 단 하나가 생기고, 값을 모두 공유한다. 그 말은 즉
```java
v1.staticVal = 20;
v2.staticVal = 30;
System.out.println(v1.staticVal);
System.out.println(v2.statiacVal);
```
위 처럼 써있으면, 뭐가 나올까? ```20, 30```?

아니다. 말했듯이 static필드(변수)는 오직 하나 존재하며 값을 공유하기 때문에 ```30, 30```이 나오게 된다.

또한 static필드는 v1.staticVal 처럼 호출하지 않는다. 단 하나 존재하는데, 굳이 클래스 인스턴스를 생성해서까지 불편하게 부르지 않는다.
```java
System.out.println(VariableScopeExam.staticVal);
```
이렇게 ```클래스명.스태틱필드``` 형식으로 호출한다.

- - -
## 열거형(enum)
