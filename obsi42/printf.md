[[가변인자 인수의 사용]]

## mandatory : implementing original printf
objective
	func to implement
	int ft_printf(const char \*, ...);
external library
	stblib : malloc. free
	unistd : write
	stdarg :  va_start, va_arg, va_copy, va_end
		[[가변인자 인수의 사용]]


## 고려해야 할 점
- 가변인자 확인
- 타입 별 오류
- 타입 별 포맷팅 플래그
- 이스케이프 시퀀스 (\\\*)


# 타입 별 상황별 처리
### %c : single char
- 캐릭터 하나 이상
- unprintable
- 
### %s : string
### %p : void \*  in hx
### %d : num in base 10
### %i : interger in base 10
### %u : unsigned num in base 10
### %x : num in base 16 : lowercase
### %X :  \" : uppercase
### \% : percent sign.

