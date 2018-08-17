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
	}

}
```
여느때와 같이 trycatch문을 사용하여 close메서드 이용하는 수고를 줄였고, new InputStreamReader(System.in)에서 가장 잘 나타나는 decorator pattern을 확인할 수 있다.
>데코레이터 패턴 : 객체에 추가적인 요건(기능)을 동적으로 첨가하는 방식, 서브클래스를 만드는 것을 통해 기능을 유연하게 확장할 수 있는 방법을 제공

- - -

# Char 단위 입출력(File)

```java
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class CharIOExam02 {

	public static void main(String[] args) {

		BufferedReader br = null;
		PrintWriter pw = null;

		try {
			br = new BufferedReader(new FileReader("src/IO/charIOExam02.java"));
			pw = new PrintWriter(new FileWriter("test.txt"));
			String line = null;
			while((line = br.readLine()) != null) {
				pw.println(line);
			}
		} catch (Exception e) {
			e.printStackTrace();
		}finally {
			pw.close();
			try {
				br.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}


	}
}
```
file을 char방식으로 읽는 과정을 설명하고 있다. 특이한 것이라면 PrintWriter를 들 수 있다.
>원래 PrintWriter 자체가 파일을 받는 방식도 버전을 거듭하며 생겼다. 따라서 FileWriter 꼭 써줄필요없지만 데코레이터 패턴으로 끼워쓰는 방식을 설명하기 위해 일부로 데코레이터 패턴으로 작성했다.

PrintWriter가 버전을 거듭하며 수정된 사항이기 때문에 따로 close메소드를 사용하여 닫아줘야 한다.
- - -

# 어노테이션

>annotation : 주석(달기)

java5에서 부터 추가된 기능이다. **@ 표시** 로 시작하며 **at** 이라고 읽는다. 우리는 오버라이드를 할때 ```@Override``` 라고 봤던 적이 있는데 이때 사용한 표현이다.

```java
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;

@Retention(RetentionPolicy.RUNTIME)
public @interface Count100 {

}
```
 Count100이란 어노테이션을 생성했다고 봐도 좋다. 어노테이션을 만들때는 ```@Retention(RetentionPolicy.RUNTIME)```을 붙여야 JVM 실행 시 감지할 수 있다고 하니 반드시 작성한다.
```java
public class MyHello {

	@Count100
	public void hello() {
		System.out.println("hello");
	}
}
```
이렇게 우린 평범한 클래스에 골뱅이 한 줄 추가했다.

```java
import java.lang.reflect.Method;

public class MyHelloExam {

	public static void main(String[] args) {

		MyHello hello = new MyHello();
		try {
			Method method = hello.getClass().getDeclaredMethod("hello");
			//getClass는 Object 클래스가 가지고 있는 메서든데
			//모든 클래스는 Object 클래스를 가지니 사용가능

			//getClass로 해당 인스턴스를 만들때 사용한 클래스의 정보를 리턴 후
			//getDeclaredMethod라는 메서드를 호출하게 되면 그 클래스에 대한 정보를
			//얻고 그 정보로부터 hello라는 이름의 메서드의 정보를 구해라 라는 의미

			if(method.isAnnotationPresent(Count100.class)) {
				//이 if가 의미하는 것은 메서드가 가지고있는 isAnnotationPresent라는
				//메서드가 특정 어노테이션이 메소드에 적용이 되어있는지 알아낼 수 있는 부분

				//저 count100이라는 annotation을 적용하고 있어요? 라는 의미임
				//맞으면 true반환
				for( int i = 0 ; i < 100 ; i++ ) {
					hello.hello();
				}
			}else {
				hello.hello();
			}
		} catch (Exception e) {
			e.printStackTrace();
		}

	}
}
```
참고로 try-catch문은 이클립스에서 요구해주는 항목이므로 내 의견과 상관없이 넣어주는것이니 신경 안써도 된다.

**우리가 직접 어노테이션이 만들어 사용하는 경우는 거의 없다.** 직접 만드는 경우는 자바를 훨씬 능숙하게 활용할때 쯤 사용할 것이고, **누군가가 만든 어노테이션을 사용할때는 설명서가 전부 달려있으니 개념만 알아보도록 하자.** 말 그대로 ***주석*** 이라는 의미이므로 가볍게 생각하자.

- - -

# 쓰레드(Thread)란?

>운영체제(Operating System) : 컴퓨터의 하드웨어를 사용하게 해주는 프로그램

우리 대부분은 MS window라는 운영체제를 사용하고 있다. 윈도우가 고장이 나면 컴퓨터를 아얘 사용하지 못하는 경우가 생긴다. 요즘 사용하는 대부분의 운영체제들은 여러가지 작업을 수행할 수 있다. 워드작업을 하면서 음악도 듣고, 인터넷 검색도 할 수 있다.

윈도우 작업관리자에 들어가면 현재 실행되는 프로세스들을 확인할 수 있다. 운영체제 입장에서 보면 자바도 하나의 프로세스도 실행하는 것이다. 워드작성시 맞춤법을 자동으로 검사해주는 것을 본 기억이 있을 것이다. 우리가 글을 입력할 때, 워드프로세서는 백그라운드에서 우리가 입력한 글을 검사한다. 워드프로세서가 하나의 프로세스라면 하나의 프로세스 안에서도 여러개의 흐름이 동작할 수 있다. 이것을 쓰레드(Thread)라고 부른다.

자바는 JVM만 있다면 어떤 운영체제에서든지 동작한다. 자바를 만든 사람들은 자바 프로그램 안에서 여러개의 흐름이 흘러가게 하도록 하고싶었다. 우리가 만든 자바 프로그램이 동시에 작업하게 하고 싶다면, 우린 쓰레드(Thread)를 공부해야 한다.

- - -

# 쓰레드 만들기(extend Thread)

```java
public class MyThread1 extends Thread {

	String str;
	public MyThread1(String str) {
		this.str = str;
	}


	@Override
	public void run() {
		for(int i = 0; i < 10 ; i++ ) {
			System.out.println(str);

			try {
				Thread.sleep((int)(Math.random()*1000));
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			};
		}
	}


}
```
이렇게 쓰레드를 구성한다. run이라는 메서드를 오버라이드하여 뭐든 시키고 싶은 일을 시킨다. 우린 생성할 때 받아온 str을 10번 찍게 만들 것이고, 컴퓨터가 너무 빠르니 컴퓨터에게 반복문 돌아가는 시간을 벌어주기위해 sleep메서드를 사용한다.
```java
public class ThreadExam {

	public static void main(String[] args) {
		MyThread1 t1 = new MyThread1("*");
		MyThread1 t2 = new MyThread1("-");

		t1.start(); //수행 흐름이 2개가 됨
		t2.start(); //수행 흐름이 3개가 됨

		System.out.println("main end !!!");
		//메인 쓰레드가 종료되도 프로그램이 종료되진 않음.
		//다른 쓰레드 모두 끝나야 프로그램이 종료됨
	}

}
```
쓰레드 객체를 2개 만들어서 각각 main에서 돌렸다. **start메서드** 를 통해서 run메서드를 돌렸고, 비록 main메서드는 시작하자마자 끝나지만, t1과 t2는 main안에 속해있지만 계속 돌아가는 것을 확인할 수 있다.

 - - -

# 쓰레드 만들기(implements Runnable)

우리는 클래스에 Thread라는 클래스를 상속받아서 쓰레드를 만들었다. 우리는 자바가 단일 상속만 지원한다는 사실을 안다. 그러면 쓰레드를 상속 받을 수 없다. 이럴때 사용하는 것이 Runnable이다.

```java
public class MyThread2 implements Runnable {

	String str;
	public MyThread2(String str) {
		this.str = str;
	}


	@Override
	public void run() {
		for(int i = 0; i<10 ; i++ ) {
			System.out.println(str);
			try {
				Thread.sleep((int)(Math.random()*100));
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

	}

}
```

기존엔 쓰레드를 상속받았지만 이번엔 runnable interface를 구현하도록 바꿨다. runnable interface는 애초에 run 매서드를 가지고있기 때문에 구현만 해주면 된다. **자바는 단일 상속만 지원하기 때문에 다른 클래스를 상속받고있을때 쓰레드 클래스를 상속받을 수 없다.** 따라서 다른 클래스를 상속받고 있다면 runnable 인터페이스를 이용한다.

```java
public class MyThreadExam2 {

	public static void main(String[] args) {
		MyThread2 t1 = new MyThread2("*");
		MyThread2 t2 = new MyThread2("-");

		//쓰레드가 run을 직접 호출x, start로 호출함
		//myt2는 thread상속받지 않아서 start메서드 안가짐
		//이상태에서 start메서드를 받을 수 없다.

		Thread thread1 = new Thread(t1);
		Thread thread2 = new Thread(t2);
		//Thread클래스를 이용하여 진짜 Thread객체를 만들어줘야함

		thread1.start();
		thread2.start();

		System.out.println("main end!!!");
	}
}
```

- - -

# 쓰레드와 공유 객체

여럿 생성될 쓰레드가 하나의 클래스(객체)를 공유하는 법을 배우자.

```java
public class MusicBox {

	public void playMusicA() {
		for(int i = 0; i<10; i++) {
			System.out.println("신나는 음악!!!");

			try {
				Thread.sleep((int)(Math.random() * 1000));
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}


	public void playMusicB() {
		for(int i = 0; i<10; i++) {
			System.out.println("슬픈 음악!!!");

			try {
				Thread.sleep((int)(Math.random() * 1000));
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}



	public void playMusicC() {
		for(int i = 0; i<10; i++) {
			System.out.println("카페 음악!!!");

			try {
				Thread.sleep((int)(Math.random() * 1000));
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
}
```
위 코드는 공유할 MusicBox라는 클래스다.
```java
public class MusicPlayer extends Thread {
	int type;
	MusicBox musicBox;

	public MusicPlayer(int type, MusicBox musicBox) {
		this.type = type;
		this.musicBox = musicBox;
	}

	@Override
	public void run() {
		switch (type) {
		case 1:
			musicBox.playMusicA();
			break;
		case 2:
			musicBox.playMusicB();
			break;
		case 3:
			musicBox.playMusicC();
			break;
		}
	}
}
```
MusicBox를 플레이 할 MusicPlayer 클래스를 만들었으며 쓰레드 클래스를 상속받았다.
```java
public class MusicBoxExam {

	public static void main(String[] args) {
		MusicBox box = new MusicBox();

		MusicPlayer kang = new MusicPlayer(1, box);
		MusicPlayer kim = new MusicPlayer(2, box);
		MusicPlayer lee = new MusicPlayer(3, box);

		kang.start();
		kim.start();
		lee.start();
	}
}

```
쓰레드 클래스를 상속받은 MusicPlayer를 이용하여 MusicBox라는 객체를 공유하는 것을 확인할 수 있다.

- - -

# 동기화 메소드와 동기화 블록

>Synchronized : 동기화

위와 다른것은 Synchronized 라는 문구를 붙여준 것 뿐이다.
```java
public class MusicBox {

	public synchronized void playMusicA() {     //수정
		for(int i = 0; i<10; i++) {
			System.out.println("신나는 음악!!!");

			try {
				Thread.sleep((int)(Math.random() * 1000));
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}


	public synchronized void playMusicB() {    //수정
		for(int i = 0; i<10; i++) {
			System.out.println("슬픈 음악!!!");

			try {
				Thread.sleep((int)(Math.random() * 1000));
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}



	public  void playMusicC() {
		for(int i = 0; i<10; i++) {
			synchronized (this) {                  //수정
				System.out.println("카페 음악!!!");
			}

			try {
				Thread.sleep((int)(Math.random() * 1000));
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}



}
```
공유객체인 MusicBox의 메서드 선언 또는 메서드 안에 Synchronized 를 삽입하였다. 먼저 호출한 메소드가 객체MusicBox의 사용권을 얻게 되는데, 이 객체 사용권을 모니터링 락(Monitoring Lock) 이라고 부른다. 만일 kang이라는 플레이어가 먼저 start()하게 되면 kang은 ```신나는음악!!!``` 을 10번 출력할때까지 **Monitoring Lock** 을 kang이 가지게 된다. Synchronized로 동기화 해줬으니 동기화된 ```슬픈 음악``` 이나 ```카페 음악```은 출력이 불가능하다.

Synchronized는 카페 음악에서 확인할 수 있겠지만 메서드 선언에서 쓸 뿐만 아니라 메서드 안에서도 동기화가 가능하다.

- - -

# 쓰레드와 상태 제어

쓰레드는 시작되었다가 멈췄다가를 반복한다. start()메서드를 실행하면 실행 가능한 상태인 runnable과 실행상태인 running을 왔다 갔다하게 됩니다.

간혹 sleep메서드나 wait메서드를 실행하여 잠시 쓰레드의 일시정지상태로 들어갈 수 있다. 이를 blocked상태가 됐다고 한다. sleep메서드는 모니터링 락을 유지하지만 wait메서드는 모니터링 락을 버리게 됩니다.

쓰레드의 run메서드가 종료되면 쓰레드가 종료되는데, dead상태가 된다. 쓰레드에 yield메서드가 호출이 되면 다른 쓰레드에게 자원을 양보하게 된다. 그 의미는 양보받은 쓰레드는 더욱 빠르게 돌아갈 수 있다.
- - -

# 쓰레드와 상태 제어(join)

join()메소드는 쓰레드가 멈출때까지 기다리게 한다.

```java
public class MyThread5 extends Thread{
	public void run() {
		for(int i=0;i<5;i++) {
			System.out.println("MyThread5 : " + i);
			try {
				Thread.sleep(500);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
}
```

```java
public class JoinExam {

	public static void main(String[] args) {
		MyThread5 thread = new MyThread5();
		thread.start();

		System.out.println("시작");


		try {
			thread.join();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}


		System.out.println("종료!");
	}

}
```

이처럼 join메서드를 쓰게되면 쓰레드가 멈출때까지 기다리므로, for문을 5번돌때까지 ```종료!```는 확인할 수 없다.

- - -

# 쓰레드와 상태제어(wait, notify)

wait와 notify는 동기화된 블록안에서 사용해야 한다. wait를 만나게 되면 해당 쓰레드는 해당 객체의 모니터링 락에 대한 권한을 가지고 있다면 모니터링 락의 권한을 놓고 대기한다.

```java
public class ThreadB extends Thread {
	int total;

	public void run() {
		synchronized (this) {
			for(int i = 0; i<5; i++) {
				System.out.println(i+"를 더합니다.");
				total += i;

				try {
					Thread.sleep(500);
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}

			notify(); //쓰레드를 깨울 수 있는 메서드 호출하게 함
		}
	}
}
```

```java
public class ThreadA {
	public static void main(String[] args) {
		ThreadB b = new ThreadB();
		b.start();
		//run을 실행시키며 모니터링 락을 획득하게 됨
		//b에 대하여 동기화 블록 설정한 것을 기억하라

		synchronized (b) {
			try {
				System.out.println("b가 완료될때까지 기다립니다.");
				b.wait();
			}catch(InterruptedException e) {
				e.printStackTrace();
			}
			System.out.println("Total is : " + b.total);
		}

	}
}
```
wait메서드를 이용하여 main쓰레드는 정지하게되고, for문을 5번 돌고 난 후, notify메서드를 만나게 되는데 그 때, main쓰레드는 깨어나게되고 main 남은 코드를 수행하게된다.

- - -

# 데몬 쓰레드

>데몬(Daemon) : 보통 리눅스와 같은 유닉스계열의 운영체제에서 백그라운드로 동작하는 프로그램을 말한다. 윈도우에서는 주로 서비스로 불린다.

- 데몬쓰레드는 자바프로그램을 만들 때 백그라운드에서 특별한 작업을 처리하게 하는 용도로 만든다.
- 데몬쓰레드는 일반 쓰레드(main 등)가 모두 종료되면 강제적으로 종료되는 특징을 가지고 있다.

```java
public class DaemonThread implements Runnable {

	@Override
	public void run() {
		while(true) {
			System.out.println("데몬 쓰레드가 실행중입니다.");

			try {
				Thread.sleep(500);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				break;//sleep하는 동안에 exception일어나면 빠져나가야 하므로 break;넣음
			}
		}

	}

	public static void main(String[] args) {
		Thread thread = new Thread(new DaemonThread());
		thread.setDaemon(true);
		thread.start();

		try {
			Thread.sleep(1000);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		System.out.println("메인 쓰레드가 종료됩니다.");
	}


}
```

원래는 while(true)로 무한루프를 돌게 되어있지만 데몬쓰레드 특성상 쓰레드가 모두 종료되면 강제로 종료되는 특징을 지닌다. 따라서 메인이 끝나는 동시에 쓰레드도 강제 종료됨을 확인할 수 있다.

- - -

# 람다식(Lambda)

>람다식 == 익명메서드

```java
public class LambdaExam {

	public static void main(String[] args) {
		new Thread(new Runnable() {

			@Override
			public void run() {
				for(int i = 0; i<10; i++) {
					System.out.println("hello");
				}

			}

		}).start();
	}
```
자바는 매서드만 매개변수로 전달할 방법이 없고, 우리가 이때까지 했던 것처럼 인스턴스만 가능했다. 따라서 우린 항상 객체를 만들어서 메서드를 전달했지만 여간 불편한게 아니었다. 따라서 이를 해결하기위해 람다표현식이 등장했다.

객체 자체를 직접 생성할 필요가 없다. 따라서 우린 new Runnable()를 없앤다. 그리고 java api에서 제공하는 람다표현식 문법을 삽입한다. 수정하면 아래처럼 바뀐다.
```java
public class LambdaExam {

	public static void main(String[] args) {
		new Thread(()-> {
				for(int i = 0; i<10; i++) {
					System.out.println("hello");
				}

		}).start();
	}

}
```
()-> 라는 표현을 삽입하면 람다표현식 문법을 사용하여 객체 생성없이 바로 메서드 사용이 가능해진다. 따라서 우린 바로 start메서드를 사용하는 것을 확인할 수 있다.

- - -

# 람다식 기본문법

>람다표현식 : (매개변수목록)->{실행문}

```java
public interface Compare {
	public int compareTo(int value1, int value2);
}
```
인터페이스만 간단히 구성했다.
```java
public class CompareExam {

	public static void exec(Compare compare) {
		int k = 10;
		int m = 20;
		int value = compare.compareTo(k, m);
		System.out.println(value);
	}


	public static void main(String[] args) {
		exec((i,j) ->{

			return i - j;
		});

	}

}
```
우리는 항상 메인에서 객체를 생성하여 메서드를 이용했지만, 마치 우리가 C언어를 공부할 때 함수를 사용하듯이 따로 객체의 생성없이 바로 exec이란 메서드를 사용하여 value값을 얻어내는 것을 확인할 수 있다. 이런 간편함을 위해 java 8에서 람다식을 업데이트하였다.
