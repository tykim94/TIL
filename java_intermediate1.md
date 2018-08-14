# Object와 오버라이딩

Object클래스 = 모든 클래스의 최상위 클래스

아무것도 상속받지 않으면 자동으로 Object클래스 상속받음

Object클래스의 3가지 메소드
1. equals : 객체가 가진 값을 비교할 때 사용
2. toString : 객체가 가지고 있는 값을 문자열로 바꾸어서 return할 때 사용
3. hashCode : 객체의 해시코드 값 반환

equals와 hashcode를 사용하려면 오버라이딩을 해주는 것이 중요하다. 굉장히 자주 사용되는 개념이라서 이클립스에서 제공해주는 기능이다.
> 상단 메뉴바 -> source -> generate hashCode() and equals() -> 값 조정

toString도 똑같이 사용 가능하다.
> 상단 메뉴바 -> source -> generate toString() -> 값 조정
- - -
# java.lang 패키지/오토박싱

java.lang 패키지는 따로 임포트하지 않아도 자동으로 사용 가능하다.

java.lang 패키지에는 기본형 타입을 객체 타입으로 변환시킬때 사용하는 **Wrapper** 클래스가 있다.
>Boolean, Byte, Short, Integer, Long, Float, Double 클래스

__Object클래스__ 도 java.lang패키지 내에 있다. 또한 문자열과 관련된 __String, StringBuffer, StringBuilder__ , 화면 값 출력에 사용한 __System, math클래스, thread와 관련된 클래스들__ 모두 java.lang에 속해있다.
```java
public class WrapperExam {

	public static void main(String[] args) {
		int i = 5;
		Integer i2 = new Integer(5);//JAVA 9부터 deprecated된 클래스임

		Integer i3 = 5; //오토박싱

		int i4 = i3.intValue();//JAVA 5 이전 사용법

		int i5 = i3; //오토언박싱, JAVA 5 이후 사용법
	}
}
```
- 오토박싱 : 기본 타입 데이터를 객체 타입의 데이터로 자동 형변환 시켜주는 기능
- 오토언박싱 : 오토박싱의 반대 개념. 객체타입의 데이터를 기본형으로 자동 형변환
- - -
# 스트링버퍼(StringBuffer)
>String클래스 : 자기 자신이 변하지 않는 불변클래스
>
>StringBuffer클래스 : 자기 자신이 변하는 클래스

StringBuffer클래스의 대부분 메소드들은 자기 자신 this를 반환하는 모습을 가지고 있다.

```java
String str2 = new StringBuffer().append("hello ").append("world").toString();
	System.out.println(str2);
```
StringBuffer클래스는 자기 자신을 반환하므로 메소드 체이닝이 가능하다.
>메소드 체이닝(method chaining) : 자기자신을 리턴하여 계속해서 자신의 메소드를 호출하는 방법

따라서 우린 ```append().append().append().toString();``` 처럼 이을 수 있다.
- - -
# 스트링 클래스의 문제점

```java
public class StringExam2 {
	public static void main(String[] args) {
    //1. 반복적인 +연산 사용 (new 사용)
		String str1 = "";
		for(int i = 0 ; i < 100 ; i++) {
			str1 = str1 + "*";
		}
		System.out.println(str1);


    //2. StringBuffer의 체이닝메서드 사용
		StringBuffer sb = new StringBuffer();
		for(int i = 0 ; i < 100 ; i++) {
			sb.append("*");
		}
		String str2 = sb.toString();
		System.out.println(str2);
	}
}
```
문자열에 문자열을 더하는 식은 ```str + str```라고 적는데, 사실 +연산은 StringBuffer클래스의 append메소드를 이용하여 문자열이 누적되고, 그 누적이 끝난 문자열을 toString()을 통하여 String객체로 바꿔주는 연산이다.

따라서 반복문 내에서 + 연산을 진행하면 new연산을 반복하게되고, 프로그램 속도가 느려지므로 지양해야한다.

해결책으로는, StringBuffer의 체이닝메서드를 이용하면 new연산을 하지 않게되어 속도가 훨씬 빨라진다.
- - -
# Math클래스
>코싸인, 싸인, 탄젠트, 절대값, 랜덤값을 구할 수 있는 클래스

- Math클래스는 생성자가 private으로 되어 있기 때문에 new 연산자를 이용하여 객체를 생성할 수 없다.
- 객체를 생성할 수는 없지만 모든 메소드와 속성이 static으로 정의되어 있기 때문에 객체를 생성하지 않고도 사용할 수 있다.

모든 메소드가 static으로 설정되어있기 때문에 ```클래스명.메소드명```으로 사용한다.

```java
Math.max(v1, v2) : v1과 v2중 큰 값 리턴
Math.min(v1, v2) : v1과 v2중 작은 값 리턴
Math.abs(v1) : v1의 절대값 리턴
Math.random() : 0 ~ 1 사이에 double값 리턴
Math.sqrt(v1) : v1의 제곱근 리턴
Math.pow(v1, v2) : v1의 v2승
Math.log10(v1) : 로그 10의 v1 (  ex> log10(100) = 2  )
```
- - -
# java.util 패키지

java.lang 패키지 다음으로 많이쓰는 java.util 패키지이다.

날짜와 관련된 **date, calender 클래스** , 자료구조와 관련된 **collection framework클래스** 유용한 클래스를 많이 가지고 있음

>deprecated란? "더이상 지원하지 않으니 사용하지 않는 것이 좋다"의 의미
- - -
# Collection Framework

자료를 다룰 수 있는 자료구조 클래스

collection framework에서 가장 기본이 되는 인터페이스는 collection interface이다.

1. Collection interface는 여기에 자료가 있다는 것을 표현함. 중복도 허용하며, 자료가 저장되는 순서는 기억 못함. collection interface가 가지는 대표적인 메소드는 add(), size(), iterator()이다.

2. Iterator interface는 자료를 하나씩 꺼낼 수 있음. 가지는 메소드는 hasNext(), next()를 가진다.

3. Set interface는 중복을 허용하지 않는 자료구조를 표현한 인터페이스입니다. collection interface를 상속받고 있으며 가지는 메소드는 add()가 있다.

4. List interface는 collection interface를 상속받고 있다. 자료를 꺼내주는 get() 메서드를 가진다.

5. Map interface는 key 와 value를 가지며 put() 메서드를 이용하여 함께 저장합니다. 꺼낼때는 key를 이용한 get()메서드를 이용한다.
- - -
# Generic
c++에서의 템플릿 문법과 같다. 가상의 타입으로 선언하는데, 클래스를 이용함에 있어서 형변환을 해야 할 귀찮음을 덜어주기위해 탄생한 문법이다.
```java
public class Box {
	private Object obj;

	public void setObj(Object obj) {
		this.obj = obj;
	}

	public Object getObj() {
		return obj;
	}
}
```

```java
box.setObj("hello");
String str = (String)box.getObj();
System.out.println(str);

box.setObj(1);
int value = (int)box.getObj();
System.out.println(value);
```
이처럼 사용하면,(String), (int)등 계속 형변환을 해야하는 수고가 든다. 하지만 아래는 Generic문법을 사용한 예시를 보이겠다.

```java
public class Box<E> {
	private E obj;

	public void setObj(E obj) {
		this.obj = obj;
	}

	public E getObj() {
		return obj;
	}
}
```
```java
Box<Object> box = new Box();
box.setObj(new Object());
Object obj = box.getObj();

Box<String> box2 = new Box();
box.setObj(4);
String str = box2.getObj();

Box<Integer> box3 = new Box<>();
box3.setObj(4);
int value = box3.getObj();
```
클래스 선언에서 ```<E>```를 붙여줌으로서 Generic을 사용함을 알린다. 그러면 처음 클래스 인스턴스 생성시에 한번만 만들 형을 명시해주면 형변환을 할 필요가 없어진다.
- - -
# Set
set은 중복이 없고, 순서도 없는 자료구조. Hashset과 TreeSet이 있다.

```java
import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

public class setExam {
	public static void main(String[] args) {

		Set<String> set1 = new HashSet<>();
		boolean flag1 = set1.add("kang");
		boolean flag2 = set1.add("kim");
		boolean flag3 = set1.add("kang");

		System.out.println(set1.size());

		System.out.println(flag1);
		System.out.println(flag2);
		System.out.println(flag3);

		Iterator<String> iter = set1.iterator();

		while(iter.hasNext()) {
			String str = iter.next();
			System.out.println(str);
		}

	}
}
```
우리는 HashSet이라는 Set클래스의 자식 클래스로 자료구조를 이용할 수 있다. 단 같은 자료는 입력이 불가능함을 알자.

Set 자체는 인터페이스이기 때문에 Set자체로 인스턴스 생성이 불가능하다. 따라서 Set으로 만든 자식클래스인 HashSet과 TreeSet 두 개중 하나를 골라 사용해야 하는데 우리는 HashSet을 사용한 것이다.

add라는 메서드는 true/false를 반환하는데 자료구조에 자료 입력이 성공하면 true, 아니면 false를 반환한다. 이처럼 입력 후 확인할 수 있다. 또한 size메서드로 자료구조의 총 크기(자료의 개수)를 알 수 있다. 여기선 kang이라는 자료가 2번 들어가므로 그걸 1개로 쳐서 2가 나온다.

또한 iterator이라는 메서드로 자료를 꺼낼 수 있는데, 그 안에서 hasNext라는 메서드를 이용하면 자료가 존재하지 않을때까지 꺼내쓸 수 있으므로 반복문과 궁합이 아주 좋은 메서드이다.
- - -
# List
```java
import java.util.ArrayList;
import java.util.List;

public class ListExam {
	public static void main(String[] args) {

		List<String> list = new ArrayList<>();
		list.add("kim");
		list.add("kang");
		list.add("kim");

		System.out.println(list.size());

		for(int i = 0; i < list.size(); i++) {
			String str = list.get(i);
			System.out.println(str);
		}

	}
}
```
list는 위의 set과 매우 흡사하다. 차이점은 중복된 데이터를 거부하지 않고 모두 저장한다.

list는 인터페이스 이고 실제 인스턴스 생성은 list로 만든 클래스인 ArrayList를 사용한다.
리스트의 크기는 size메서드를 사용하고, list의 데이터를 받을때는 get메서드를 사용한다.
- - -
# Map

```java
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;

public class MapExam {

	public static void main(String[] args) {
		Map<String, String> map = new HashMap<>();
		map.put("001", "kim");
		map.put("002", "lee");
		map.put("003", "choi");

		map.put("001", "kang");

		System.out.println(map.size());

		System.out.println(map.get("001"));
		System.out.println(map.get("002"));
		System.out.println(map.get("003"));

		Set<String> keys = map.keySet();

		Iterator<String> iter = keys.iterator();
		while(iter.hasNext()) {
			String key = iter.next();
			String value = map.get(key);
			System.out.println(value);
		}
	}

}
```
하나의 map엔 두 가지 값이 들어가는데, key값과 value가 들어간다. value는 입력하고싶은 데이터이고 key값은 데이터를 찾을때 사용하는 키워드이다. 따라서 입력할때는 ```map.put("001","kim");```이런 식으로 작성한다. map의 value를 확인하고 싶을때는 get메서드를 이용하는데 key를 인수로 넘기면 key에 저장된 value를 반환한다.

또한 key만 꺼내서 Set자료구조에 넣을 수 있는데 이렇게하면 반복문을 통해 Set의 Iterator클래스를 통해 받아서 모든 value를 받아 볼 수 있다.
- - -
# Date
```java
import java.text.SimpleDateFormat;
import java.util.Date;

public class DateExam {

	public static void main(String[] args) {
		Date date = new Date();
		System.out.println(date.toString());

		SimpleDateFormat ft = new SimpleDateFormat("yyyy.MM.dd 'at' hh:mm:ss a zzz");

		System.out.println(ft.format(date));

		System.out.println(date.getTime()); //long타입으로 시간 나타낼수있다

		long today = System.currentTimeMillis();
		System.out.println(today);

		System.out.println(today - date.getTime());
	}
}
```
시간을 나타내고 싶을때 사용 가능한 클래스이며, java.util안에 속해있다. String의 형태로 날짜와 시간을 나타낼 수도 있고, 원하는 형식(SimpleDateFormat)으로도 사용할 수 있다.
- yyyy : 연도
- MM : 월
- dd : 일
- '어쩌구저쩌구' : 원하는 문구 입력 가능
- hh : 시
- mm : 분
- ss : 초
- a : 오후, 오전 구분
- zzz : 국가표준시(우리나라는 KST라고 뜬다)

시간을 string뿐만 아니라 long타입으로도 나타낼 수 있다. getTime이라는 메서드를 사용하면 long타입으로 만들 수 있고 System안의 currentTimeMillis로도 long타입을 만들 수 있다.
- - -
# calendar
```java
import java.util.Calendar;

public class CalenderExam {

	public static void main(String[] args) {
		Calendar cal = Calendar.getInstance();
		System.out.println(cal.get(Calendar.YEAR));
		System.out.println(cal.get(Calendar.MONTH) + 1);
		System.out.println(cal.get(Calendar.DATE));

		System.out.println(cal.get(Calendar.HOUR));
		System.out.println(cal.get(Calendar.HOUR_OF_DAY));
		System.out.println(cal.get(Calendar.MINUTE));
		System.out.println(cal.get(Calendar.SECOND));

		cal.add(Calendar.HOUR, 5);//5시간 후로 만들기

		System.out.println(cal.get(Calendar.HOUR));
	}

}
```
>calendar클래스를 이용하여 인스턴스를 만드는 코드를 살펴보면 이때까지와는 다른 점을 알 수 있다. new 생성자를 쓰지 않는데, 이유는 Calandar는 추상클래스라서 스스로 자기 자신을 만들어 리턴할 수 없다.
>
>따라서 이때까지처럼 추상클래스로 만든 자식클래스를 이용하여 인스턴스를 만들 수 있지만, 후에 새로운 형식의 표준 달력이 나오면 또 외우기 귀찮으므로 JDK의 배려라고 보면 좋다. 따라서 new가 아닌 getInstance메서드를 이용하여 인스턴스를 생성하도록 하자.

get(Calendar.MONTH)는 0~11월이라고 표현이 되도록 구현되어있는데 일상적으로 우리가 쓰는 1~12월하곤 다르다. 따라서 가시성을 위해 +1하여 사용하는 것이 일반적이다.
- - -
# java.time 패키지
java의 Date클래스는 직관적이지 못해 개발자들이 사용을 꺼렸는데, 따라서 개발자들은 써드파티에서 제공하는 Joda-Time라이브러리를 사용하였다. 이런 문제점을 해결하고 좀 더 직관적인 api들을 제공하기 위해서 Java SE 8부터 새롭게 디자인한 Date,Time Api를 제공하였다.

```java
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.LocalTime;
import java.time.Month;

public class TimeExam {

	public static void main(String[] args) {
		LocalDateTime timePoint = LocalDateTime.now();
		System.out.println(timePoint);

		LocalDate ld1 = LocalDate.of(2012, Month.DECEMBER, 12);
		System.out.println(ld1);

		LocalTime lt1 = LocalTime.of(17, 18);
		System.out.println(lt1);

		LocalTime lt2 = LocalTime.parse("10:15:30");
		System.out.println(lt2);

		LocalDate theDate = timePoint.toLocalDate();
		System.out.println(theDate);
		Month month = timePoint.getMonth();
		System.out.println(timePoint.getMonth());
		System.out.println(month.getValue());
		System.out.println(timePoint.getHour());
	}
}
```

위처럼 현재 시각을 구할 수도 있고, 원하는 시간으로 time객체를 생성할 수도 있고, getMonth나 getHour같은 메서드로 현재의 날짜와 시간정보를 구할 수도 있다.
