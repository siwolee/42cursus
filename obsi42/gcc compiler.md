
http://doc.kldp.org/KoreanDoc/html/gcc_and_make/gcc_and_make-2.html

# \-I 옵션 (header dir)

#include 문장에서 지정한 헤더 화일이 들어있는 곳을 정하는 옵션입니다. 아주 많이 사용되는 옵션 중 하나입니다.

---

 #include <stdio.h>
 #include "my_header.h"

---

전자( <> 문자를 쓴 경우 )는 시스템 표준 헤더 디렉토리인 /usr/include를 기준으로 화일을 찾아서 포함시킵니다. 표준 디렉토리이지요.

후자( "" 문자를 쓴 경우 )는 지금 컴파일러가 실행되고 있는 현재 디렉토리를 기준으로 헤더 화일을 찾습니다.

이 두 디렉토리가 아닌 곳에 대해서는 명시적으로 -I<디렉토리> 로 정해줍니다.

 $ gcc -c myprog1.c -I..
 $ gcc -c myprog1.c -Iinclude

첫번째는 헤더 화일이 현재 소스 하위 디렉토리(..)에 있다는 뜻이며 두번째는 현재 디렉토리의 include라는 디렉토리에 들어있다는 뜻입니다.

-I 옵션은 얼마든지 여러번 쓸 수 있으며 주어진 순서대로 헤더 화일을 검색합니다.

****주의****

<font color="#00b050">디렉토리명은 -I 라는 문자 바로 다음에 붙여서 씁니다. 즉 -I <디렉토리>라는 식이 아니라 -I<디렉토리> 입니다. </font>또한 유닉스에 있어 표준 헤더 화일 디렉토리는 /usr/include 라는 사실을 기억하시기 바랍니다. 또한 리눅스에 있어서는 커널 소스가 아주 중요한데 리눅스 고유의 기능을 쓰는 리눅스용 프로그램의 경우에는 /usr/include/linux, /usr/include/asm, /usr/include/scsi (최신 커널의 경우) 라는 디렉토리가 꼭 있어야 하며 각각은 커널 소스의 헤더 디렉토리에 대한 링크입니다. 따라서 커널 소스를 꼭 설치해두셔야 합니다.

 /usr/include/linux   -------------->  /usr/src/linux/include/linux
 /usr/include/asm     -------------->  /usr/src/linux/include/asm  
 /usr/include/scsi    -------------->  /usr/src/linux/include/scsi

( 위에서 /usr/src/linux/include/asm은 사실 대부분의 경우 /usr/src/linux/include/asm-i386 이라는 디렉토리에 대한 링크입니다 )

각각 linux는 일반적인 C 헤더 화일, asm은 각 아키텍쳐별 의존적인 어셈블리 헤더 화일, 맨 마지막은 SCSI 장치 프로그래밍에 쓰이는 헤더 화일이 들어있는 곳입니다.

일반적으로 커널 소스( 약 6 메가 이상되는 소스 )는 /usr/src 에서 tar, gzip으로 풀어두는 것이 관례입니다.

맨 처음 프로그래밍을 할 때는 그렇게 많이 쓰지는 않는 옵션이지만 여러분이 다른 소스를 가져다 컴파일할 때 아주 많이 보게 되는 옵션이므로 일단 이해는 할 수 있어야겠죠?




# \-l 옵션과 \-L 옵션

링크(link)할 라이브러리를 명시해주는 옵션이 바로 -l ( 소문자 L ) 옵션입니다.

-I 옵션과 마찬가지로 바짝 붙여서 씁니다. 절대 떼면 안됩니다.

우리는 libmylib.a 라는 라이브러리를 만들어두었습니다. 그것을 사용하기 위해서는 -lmylib 라고 적어줍니다. 라이브러리 화일명에서 어떤 글자들을 떼내고 쓰는지 주목하십시요.

 libmylib.a
    ^^^^^

ld 는 유닉스에서 사용되는 링커(Linker)입니다. C 프로그램 컴파일의 맨 마지막 단계를 맡게 되지요.

위에서 우리는 다음과 같은 에러 메세지를 만났습니다.

 ld: cannot open -lmylib: No such file or directory

자, 이제 배워야 할 옵션은 ``라이브러리의 위치를 정해주는'' -L ( 대문자 L ) 옵션입니다. 사용형식은 -L<디렉토리명> 입니다.

리눅스에서 어떤 라이브러리를 찾을 때는 /lib, /usr/lib, /usr/local/lib와 같은 정해진 장소에서만 찾게 되어 있습니다. 그것은 규칙이지요.

중요한 사실은 아무리 여러분 라이브러리를 현재 작업 디렉토리에 놓아두어도 ld 는 그것을 찾지 않는다는 사실입니다. ld 더러 라이브러리가 있는 장소를 알려주려면 다음과 같이 -L 옵션을 붙이십시요.

 $ gcc -o say_linux hello.c -lmylib -L.
                                    ^^^