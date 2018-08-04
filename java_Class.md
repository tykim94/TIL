# java_Class
- - -
```java
public class Car{

   }
```
- Car.java 파일이다.
- 저장을 하면 이클립스는 컴파일하여  디스크에 Car이라는 클래스 생성한다.
- __자동차 클래스가 생성되었다고 해서 자동차가 만들어 진것은 아니다.__
- - -
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
메소드는 수학의 함수와 비슷하며, 입력값을 받아서 결과값을 낸다.

>입력값 : 매개변수(parameter), 인자(argument)
>
>결과값 : 리턴값
>

>매개변수 : 전달된 인자를 받아들이는 변수를 의미
>
>인자 : 어떤 함수를 호출할 때 전달되는 값 자체를 의미
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

특정 값만 가졌으면 좋겠을 때?

JDK5 이전에는 상수를 이용하였다.
```java
public class EnumExam {
       public static final String MALE = "MALE";
       public static final String FEMALE = "FEMALE";

       public static void main(String[] args) {
           String gender1;

           gender1 = EnumExam.MALE;
           gender1 = EnumExam.FEMALE;        

           gender1 = "boy"; //문제 발생! 컴파일은 되지만 의도 벗어남
       }
}
```

위처럼 final을 이용해 상수로 만들어줬다. 하지만 여기서의 문제점은 main안에서의 gender1이 String타입이기 때문에, 변수 값이 변하게되는데, 개발자의 의도와 벗어나게 된다. 따라서 우린 enum이라는 열거형을 사용한다.

```java
enum Gender{
        MALE, FEMALE;
}

public static void main(String[] args) {
    Gender gender2;

    gender2 = EnumExam.MALE;
    gender2 = EnumExam.FEMALE;        

    gender2 = "boy"; //컴파일 에러!!
}
```
이처럼, 특정 값만 가져야 한다면 열거형을 사용하는 것이 좋다.
- - -
## 생성자
```java
public class Car {
	String name;
	int number;

	public Car(String n) {
		name = n;
	}
}
```

클래스 안에 클래스명 Car을 가진 리턴타입이 없는 블럭을 확인할 수 있다. 이를 __생성자__ 라고 부른다.
- - -
## This

This는 객체 자신을 참조하는 키워드이다.
```java
public class Car{
        String name;
        int number;

        public Car(String name){
            name = name;
        }
    }
```
위의 name이 클래스 내 field의 name인지, 파라메터의 name인지 컴퓨터는 알 방도가 없다. 따라서 우리가 따로 지정해 줘야 하는데, field의 name 앞에 this키워드를 붙인다.
```java
public class Car{
        String name;
        int number;

        public Car(String name){
            this.name = name;
        }
    }
```
또한 클래스 안에서 자기 자신이 가지고 있는 메소드를 사용할 때도 this.메소드명()으로 호출할 수 있다.
- - -
## 메소드 오버로딩
```java
class MyClass2{
       public int plus(int x, int y){
           return x+y;
       }

       public int plus(int x, int y, int z){
           return x + y + z;
       }

       public String plus(String x, String y){
           return x + y;
       }

       public int plus(int i, int j){   //컴파일 에러, 메소드 중복
           return x + y;
       }
   }
```

위처럼 오버로딩이 가능하지만, 오버로딩과 중복은 다르다.

메소드명이 백번 천번 중복은 가능하지만, 각각의 매개변수 타입과 개수는 달라야 한다. 위처럼 매개변수가 int형 2개를 받는 네 번째 메소드는 duplicate error로 컴파일이 불가능하다.
- - -
## 생성자 오버로딩과 this
```java
public class Car {
	String name;
	int number;

  //새롭게 만든 생성자
	public Car(String name) {
		this.name = name;
	}

  //기본 생성자
  public Car(){

  }

  public Car(String name, int number){
    this.name = name;
    this.number = number;
  }
}
```

생성자 오버로딩을 진행한 모습이다. 기본 생성자(매개변수 아무것도 없는 생성자)을 이렇게 디폴트 값을 주고싶을 수도 있다.
```java
public Car(){
  this.name = "이름없음";
  this.number = 0;
}
```
하지만 이렇게 할 필요도 없이, this를 이용하자.
```java
public Car(){
  this("이름없음", 0);
}

public Car(String name, int number){
  this.name = name;
  this.number = number;
}
```
```this("이름없음", 0);``` 은 아래 string과 int를 매개변수로 가지는 생성자를 부를 수 있다.

- - -
# 패키지
클래스 관리를 위해 사용하는 것이 패키지이다. 패키지를 만들 때는 회사의 도메인을 거꾸로 적은 후 프로젝트 명을 적어준다.

> 도메인 이름이 naver.com이고 프로젝트 이름이 javastudy라면 패키지명은
```com.naver.javastudy``` 가 된다.

패키지에 생성된 클래스를 다른 패키지에서 사용하려고 접근하면 접근 불가능하다. 다른 패키지의 클래스를 꺼내 쓸 때는 "나 어디에서 가져다 쓰는거야~"라고 언급해 줘야한다.

```java
import com.naver.javastudy.Hello;
```
com.naver.javastudy라는 패키지에서 Hello.java 라는 클래스를 꺼내 쓰려고 맨 위에 적어준다. 이를 직접 적어줄 필요는 없고, 클래스 인스턴스를 생성 하는 문장을 작성 후, 컴파일 에러로 빨간줄이 그어지면, 그때 ```Ctrl + Shift + O```를 사용하면 자동으로 위에 import가 이뤄진다.

```import com.naver.javastudy.*;```라는 표현을 쓸 수도 있는데, com.naver.javastudy라는 패키지에 포함된 모든 java클래스를 import시키는 기능이다.
