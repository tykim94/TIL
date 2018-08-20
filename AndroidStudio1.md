# 안드로이드
- - -

## 1. 안드로이드어플 IDE 다운로드

안드로이드 앱을 만들기 위해 안드로이드 스튜디오를 깔았다. JDK도 필수적으로 다운받아야 했는데 운이 좋게도 최근에 JAVA를 공부하면서 깔아놔서 최신버전 JDK를 받아놨다. 환경변수 설정으로 애먹을 필요없이 안드로이드 스튜디오만 깔아서 나름 금방했다.

안드로이드 스튜디오 안에 안드로이드SDK라는 것이 존재하는데 여기선 안드로이드 플랫폼(안드로이드 버전관리) 라든지, 안드로이드 SDK 툴(에뮬레이터 등)을 제공해 주는데 스튜디오를 깔면서 자동으로 깔려서 간편했다.

- - -

## 2. 안드로이드 개발 시작하기

우선 프로젝트를 만드는 것은 다른 개발 툴처럼 똑같았다. 프로젝트 이름 설정하고, 회사 이름 설정하고 기타등등.. 신기한건 안드로이드 개발 툴이라 그런지 Phone or Tablet, Wear, TV, Android Auto, Glass 등 여러 IOT환경에 맞춰 개발하기 편하게 만들어놨다. 또한 우린 어플을 만들며 중간중간 만든 결과물을 확인하기 위해 에뮬레이터를 설정해야했다. 나는 Nexus 5 버전으로 에뮬레이터를 만들었다. 에뮬레이터 설정까지 완료하면 개발의 문을 열게 된다.

- - -

## 3. 실행 버튼

오른쪽 위에 실행 버튼을 누르면 처음 세팅인 ```Hello World!``` 가 핸드폰 화면에 뜬다. 물론 핸드폰 화면은 내가 만든 가상 디바이스(Nexus 5)에 뜨는건데, 너무 오래걸려서 해결책을 찾다보니 내 핸드폰을 연결하여 결과를 확인할 수 있었다. 핸드폰 USB 디버깅이 필요한데
> 설정->휴대폰 정보->소프트웨어 정보->빌드번호 계속 타다다닥 누르기->개발자 모드 뚫림->개발자 옵션->USB 디버깅 체크

이런 방식으로 접근하여 USB 디버깅을 허용한 후 핸드폰으로 개발 중간중간 실행 버튼을 눌러 확인할 수 있다.

- - -

## 4. 개발환경 둘러보기

우선 ```.java``` 파일과 ```.xml``` 두 가지가 존재한다. ```.java```파일은 뭐 어떤 기능을 만들어 주고 싶을 때 사용하는것 같고, ```.xml```은 html같은 mark-up language 처럼 생겼다. 실제 ```xml```의 의미는 eXtensible Markup Language의 약자로써 결론적으로 마크업랭귀지가 맞다. ```.xml```도 각각 하는일이 다르다.

- - -

## 5. 어플명 바꾸기

1. res -> values -> strings.xml 들어가기

2. ```<string name="app_name">Title</string>```

  이 부분에서 Title이란 부분을 지우고 원하는 이름을 넣으면 어플명이 된다.

- - -

## 6. 어플 타이틀 바 색상 바꾸기

1. res -> values -> colors.xml 들어가기

2. 코드 바로 왼쪽에 일렬로 세 개의 색깔 칠해진 네모가 보인다. 가장 위의 네모 클릭

3. 원하는 색깔 선택

- - -

## 7. 기존의 Hello World! 수정하기

1. res -> layout -> activity_main.xml 들어가기

2. ```<TextView``` 아래에서 ```android:text="Hello World!"``` 찾는다

3. 원하는 문구로 수정

참고로 그 주변의 layout_width, layout_height 같은 코드의 변수 수정으로 크기 조절도 가능하다.

- - -

## 8. 버튼 만들기

1. res -> layout -> activity_main.xml 들어가기

2. 아래 Design과 Text 두 버튼 확인하기

3. Design 클릭

4. Palette -> Buttons 들어가기

5. Button 이라 써있는 가장 심플한 버튼 드래그 후 옆의 핸드폰 화면에 드랍

```
핸드폰에 아무것도 안보이는 경우도 존재한다.
기존의 hello world도 안보이고 방금 드랍한 버튼도 안보인다. 이 때는,

1. res -> values -> styles.xml 들어가기

2. <style name="AppTheme" parent="Theme.AppCompat.Light.DarkActionBar"> 확인

3. <style name="AppTheme" parent="Base.Theme.AppCompat.Light.DarkActionBar">

   위에 처럼 수정. Base.를 붙인다.



그러면 Design의 핸드폰 화면에서 볼 수 있다.
```

- - -

## 9. 버튼 크기 조절

1. res -> layout -> activity_main.xml 들어가기

2. 아래 Design과 Text 두 버튼 확인하기

3. Text 클릭

4. 아까와 다르게 새로 생긴 ```<Button``` 확인 가능하다.

5. 코드 ```android:layout_width="fill_parent"```로 수정한다.

6. 버튼이 화면에 가로로 꽉 차는것을 확인할 수 있다.


```
수정했지만 버튼 크기가 그대로일 수 있다.
Text의 버튼에 노란줄이 쳐져있을 수도 있다.
마우스를 올려보면 This view is not constrained 라는 에러가 뜬다.

해결법은 Design으로 들어간다. 버튼을 누른다.

그 후 핸드폰 화면 위의 메뉴 중 요술봉처럼 생긴 아이콘에 마우스를 올려본다.

Infer Constraints 라고 뜨면 잘 찾았다.

누르면 코드가 일부 수정되기도 하고, 원하는 대로 버튼의 크기가 잘 수정된다.
```

>```fill_parent```뿐 아니라 ```wrap_content```를 사용하여 화면에 적절한 크기로 만들 수도 있다.

- - -

## 10. 버튼 클릭 시 반응하는 기능

1. 버튼을 만든다.

2. MainActivity.java 파일에 들어간다.

3. 코드를 작성한다.

```java
Button button1 = (Button) findViewById(R.id.button1);
button1.setOnClickListener(new View.OnClickListener() {
    public void onClick(View V) {
        Toast.makeText(getApplicationContext(), "버튼이 눌러졌습니다.", Toast.LENGTH_SHORT).show();
    }
} );
```

버튼을 누르면 이제 하단에 ```버튼이 눌러졌습니다.```가 뜨게 된다.

토스트(Toast) 메시지는 메시지가 나타났다가 사라지는 기능을 가진 메시지로 안드로이드 앱을 사용하다 보면 흔히 볼 수 있는 메시지이다.

만일 LENGTH_SHORT 를 LENGTH_LONG 으로 바꾸면 나타나는 시간이 길어진다.

- - -

## 11. 버튼 클릭 시 웹사이트로 이동하는 기능

1. 버튼을 만든다.

2. MainActivity.java 파일에 들어간다.

3. 코드를 작성한다.

```java
Button button1 = (Button) findViewById(R.id.button1);

button1.setOnClickListener(new View.OnClickListener(){
   public void onClick(View V) {
      Intent myIntent = new Intent(Intent.ACTION_VIEW, Uri.parse("http://www.naver.com"));
                startActivity(myIntent);
            }
        } );
```

버튼을 누르면 이제 네이버로 이동하게 된다.

new Intent : 인스턴트화

- - -

## 12. 다른 화면으로 이동하기

1. MainActivity가 있는 폴더 오른쪽 클릭 -> new -> Activity -> Empty Activity

2. OneActivity, TwoActivity 2개 생성

3. layout에도 activity_one, activity_two가 생긴 것을 알 수 있음

4. MainActivity.java 파일을 연 후 코드를 작성한다.

```java
       Button button1 = (Button) findViewById(R.id.button1);
       Button button2 = (Button) findViewById(R.id.button2);

       button1.setOnClickListener( new View.OnClickListener() {
           public void onClick(View v) {
               Intent intent = new Intent(MainActivity.this, OneActivity.class);
               startActivity(intent);
           }
       });

       button2.setOnClickListener( new View.OnClickListener() {
           public void onClick(View v) {
               Intent intent = new Intent(MainActivity.this, TwoActivity.class);
               startActivity(intent);
           }
       });
```

- - -

## 13. 간단한 브라우저 만들기

1. activity_main에 WebView를 Palette에서 꺼낸다.

2. MainActivity에 코드를 수정한다.

```java
WebView web;

@Override
protected void onCreate(Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);
    setContentView(R.layout.activity_main);
    // 위의 4문장은 원래 존재하던 문장이다.


    web = (WebView) this.findViewById(R.id.webView2);
    web.setWebViewClient(new WebViewClient());
    web.loadUrl("http://m.daum.net");
```

3. 이대로 만들고 실행하면 에러가 뜬다. 웹뷰(WebView)를 추가할 때는 항상 인터넷을 사용한다는 설정을 해야 하는데, 인터넷 사용 설정을 하지 않아 생기는 오류이다.

4. manifests -> AndroidManifest.xml 파일을 클릭하여 코드를 추가한다.

```xml

<?xml version="1.0" encoding="utf-8"?>
<manifest xmlns:android="http://schemas.android.com/apk/res/android"
    package="com.example.kimty.yoyo">

    <uses-permission android:name="android.permission.INTERNET"/>
    <!-- 이 한 문장만 추가하면 된다. 인터넷 사용을 허가한다는 내용이다. -->
```

- - -

## 13-2. 뒤로가기, 새로고침, 앞으로가기 버튼 만들기

1. activity_main.xml 을 연다.

2. 버튼 세 개를 삽입한다.

3. MainActivity.java에 코드를 추가한다.

```java
Button btn1 = (Button) findViewById(R.id.button6);
Button btn2 = (Button) findViewById(R.id.button7);
Button btn3 = (Button) findViewById(R.id.button8);

btn1.setOnClickListener(new View.OnClickListener() {
    public void onClick(View v) {
            web.goBack();
        }
});

btn2.setOnClickListener(new View.OnClickListener() {
    public void onClick(View v) {
        web.reload();
    }
});

btn3.setOnClickListener(new View.OnClickListener() {
    public void onClick(View v) {
        web.goForward();
    }
});
```

- - -

## 14. 버튼 클릭 시, 사운드 재생

1. res파일을 오른쪽 클릭한 후, new -> Android resource directory 클릭

2. raw라는 파일을 새로 만들고 안에 음악 파일을 넣습니다.

3. 버튼을 만듭니다.

4. MainActivity.java 에 코드를 추가합니다.

```java
SoundPool soundf;
Button btn;
int tom;

@Override
protected void onCreate(Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);
    setContentView(R.layout.activity_main);

    soundf = new SoundPool(1, AudioManager.STREAM_MUSIC, 0);
    tom = soundf.load(this, R.raw.drum4,1);

    btn = (Button)findViewById(R.id.button9);
    btn.setOnClickListener(new View.OnClickListener() {
        public void onClick(View v) {
            soundf.play(tom,1,1,0,0,1);

        }
    });
}
```
버튼을 누르면 drum4라는 음악이 나올 수 있도록 만들었다.

```soundf.play(a,b,c,d,e,f)``` 인자가 굉장히 많으므로 나누어 설명하겠다.

- a : **int sounded** - 사운드 파일을 구분하기 위한 int형 구분자
- b : **float leftVolume** - 사운드 왼쪽 볼륨(소리 크기 범위는 0과 1)
- c : **float rightVolume** - 사운드 우측 볼륨(소리 크기 범위는 0과 1)
- d : **int priority** - 사운드 우선 순위
- e : **int loop** - 재생 반복 1은 1회, 2는 2회, -1은 무한 반복
- f : **float rate** - 재생 속도, 1은 정상 속도, -1은 느리게, 2는 빠르게

- - -

## 15. 나인패치 이미지

- - -

## 16. 경고창 만들기

1. MainActivity.java에 들어가서 아래 코드를 입력한다.

```java
AlertDialog.Builder alert_confirm = new AlertDialog.Builder(MainActivity.this);
        alert_confirm.setMessage("지금 실행되고 있는 앱을 종료하겠습니까?").setCancelable(false).setPositiveButton("네", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {
                finish();
            }
        }).setNegativeButton("아뇨", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {

                return;
            }
        });
        AlertDialog alert = alert_confirm.create();
        alert.show();
```

메서드를 계속 이어 사용하는 체이닝 메서드 문법을 이용하여 경고창과 아니오, 예 창을 한번에 만들었다. ```alert_confirm``` 부터 ```AlertDialog``` 바로 전까지 한 문장으로 체이닝 되어있는 것을 확인할 수 있다. onClick 메서드가 연거푸 사용되는 만큼 오버라이딩되어 사용하는 것도 확인할 수 있다.

- - -

## 17. 앱의 인트로 화면 만들기
