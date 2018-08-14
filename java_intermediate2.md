# 자바 IO

I는 input, O는 output이다. 자바 프로그램이 동작하는데 프로그램 안으로 들어오는 모든 데이타를 input data라고하고, 프로그램상에서 파일,네트워크,콘솔같은 밖으로 나가는 값을 output data라고 한다. IO는 그렇게 입력과 출력에 대한 인터페이스와 클래스들이라고 기억하자.

자바IO는 크게 바이트단위의 입출력(Byte)과, 문자단위의 입출력(Char)으로 나뉘어진다. <u>바이트단위의 입출력 클래스는 모두 Input stream과 Output stream</u>이라는 추상클래스를 상속받아 만들어지게 된다. <u>문자단위의 입출력은 모두 Reader라는 추상클래스와 Writer</u>라는 추상 클래스를 상속받아 만들어지게 된다.

우리는 원하는 프로그램을 만들때, 다양한 입력을 받고, 다양한 출력을 한다. 그런 데이터의 입,출력을 도와주는게 자바IO클래스이다.

자바IO는 흔히 **데코레이터 패턴(Decorator pattern)** 이라고 한다. **데코레이터 패턴** 이란 *하나의 클래스를 장식 하는 것처럼 생성자에서 감싸서 새로운 기능을 계속 추가 할 수 있도록 클래스를 만드는 방식이다.*

- - -

# Byte 단위 입출력
```java
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class ByteExam1 {

	public static void main(String[] args) {
		FileInputStream fis = null;
		FileOutputStream fos = null;

		try {
			fis = new FileInputStream("src/javaIO/ByteExam1.java");
			fos = new FileOutputStream("byte.txt");

			int readData = -1;

			while((readData = fis.read()) != -1) {
				//파일이 끝날때 read메서드는 -1을 return한다.
				fos.write(readData);
			}

		} catch (Exception e) {
			e.printStackTrace();
		} finally {

			try {
				fos.close();
			} catch (IOException e) {
				e.printStackTrace();
			}

			try {
				fis.close();
			} catch (IOException e) {
				e.printStackTrace();
			}

		}
	}
}
```

컴파일 돌리면 byte.txt라는 파일이 src라는 root폴더에 저장되게된다. 내용은 fis로 가리킨 ByteExam1.java파일의 코드가 그대로 작성된다.

try,catch문은 Java SE에서 요구하는 조건이기 때문에 적었다.

- - -

# Byte 단위 입출력 심화

바로 위의 코드는 1바이트씩 읽었다면 이번엔 512바이트씩 읽어서 저장한다.

```java
int readCount = -1;
byte[] buffer = new byte[512];
while((readCount = fis.read(buffer)) != -1) {
//파일이 끝날땐 -1을 return한다.
fos.write(buffer, 0, readCount);
//buffer로 받고, 0번째부터 시작, readCount만큼 쓴다.
			}
```

왜 하필 500도 아니고 512일까? 우리가 사용하는 운영체제는 1바이트씩 읽으라 명령하든 512바이트씩 읽으라 명령하든 **항상 512바이트씩 읽어서 처리한다.** 1바이트씩 읽으라 명령한다면 511바이트는 쓰지도 않고 버리고 새롭게 다음 바이트를 읽는다. 따라서 성능을 최대한 끌어올리기 위해 **512의 배수만큼 바이트를 읽어서 파일을 읽는게 이득이다.**

- - -

# 다양한 타입의 출력

javaIO사용에 있어서 인스턴스를 만든 후 사용이 끝나면 close메서드를 호출해야한다. 위의 코드를 확인해봐도 finally에서 input과 output 둘 다 close를 호출한 것을 확인할 수 있다.

close()메소드를 사용자가 호출하지 않더라도, Exception이 발생하지 않았다면 자동으로 close()가 되게 할 수 있는 방법이 있는데 바로 try-with-resources이다. try의 인자를 적는 부분에 인스턴스 생성 선언을 하고 try박스 안에 그 객체를 사용하고, 예외가 발견되지 않았다면 자동으로 close시켜준다.

```java
import java.io.DataOutputStream;
import java.io.FileOutputStream;

public class ByteExam3 {
	public static void main(String[] args) {

		try(
           DataOutputStream out = new DataOutputStream(new FileOutputStream("data.txt"));
           ) {
			out.writeInt(100);
			out.writeBoolean(true);
			out.writeDouble(50.5);
		}catch(Exception e) {
			e.printStackTrace()
    }

  }
}
```

DataOutputStream은 여러가지 타입을 모두 저장할 수 있는데, int형도 가능하고 boolean도 가능하고 double형도 가능하다. 만들어진 txt를 읽어보면 우리가 원하는 ```100true50.5```를 확인할 수는 없는데, DataInputStream으로 읽어야만 정상적으로 읽을 수 있다.

- - -

# 다양한 타입의 입력

```java
import java.io.DataInputStream;
import java.io.FileInputStream;

public class ByteExam3 {

	public static void main(String[] args) {
		try(
				DataInputStream in = new DataInputStream(new FileInputStream("data.txt"));
			){
			int i = in.readInt();
			boolean b = in.readBoolean();
			double d = in.readDouble();

			System.out.println(i);
			System.out.println(b);
			System.out.println(d);
		}catch(Exception e) {
			e.printStackTrace();

		}
	}
}
```
위에서 만든 txt파일인 data.txt를 읽는 것을 실패했으므로 DataInputStream으로 읽는 예시이다. 여기서도 try-with-resources법칙을 사용하여 만들었기 때문에 close매서드를 따로 호출하지 않아도 컴파일 가능하다.

- - -

# Char 단위 입출력(Console)
```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class CharIOExam01 {

	public static void main(String[] args) {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line = null;
		try {
			line = br.readLine();
		} catch (IOException e) {
			e.printStackTrace();
		}

		System.out.println(line);
//우린 키보드입력을 받아서 읽었지만 파일입력을 받을수도 있고 연결리스트에서 받을수도있다.
	}

}
```
여느때와 같이 trycatch문을 사용하여 close메서드 이용하는 수고를 줄였고, new InputStreamReader(System.in)에서 가장 잘 나타나는 decorator pattern을 확인할 수 있다.
>데코레이터 패턴 : 객체에 추가적인 요건(기능)을 동적으로 첨가하는 방식, 서브클래스를 만드는 것을 통해 기능을 유연하게 확장할 수 있는 방법을 제공

- - -

# Char 단위 입출력(File)

- - -

# 어노테이션
