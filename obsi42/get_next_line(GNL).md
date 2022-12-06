> 호출 반복이 될 때 한 줄씩 읽어서 반환하는 함수 구현하기.

## 파일 구성
- get_next_line.c : main func.
- get_next_line_utils.c : helper functions
- get_next_line.h - stdlib / unistd

## 조건
- return : line that was read.
	ex 1. nothing else to read
	ex 2. error occur - malloc error, NULL return
- exturnal functs. : read, malloc, free

## 주의사항
- include \n : except file ends without \n
- ==-D BUFFER_SIZE=n== add It will define the buffer size for read() / it will be modified
	-D name=definition
	The contents of definition are tokenized and processed as if they appeared during translation phase three in a ‘#define’ directive. In particular, the definition is truncated by embedded newline characters.
-  _We consider that `get_next_line` has undefined behavior if, between two calls, the same file descriptor switches to a different file before reading everything from the first fd._
    
    만약 동일한 파일 디스크립터의 두 호출 사이에서, 첫 번째 fd에서 EOF에 도달하기 전에 다른 파일로 전환될 경우, 우리는 `get_next_line`이 정의되지 않은 동작을 가진다고 생각합니다.
-   _Finally we consider that `get_next_line` has undefined behavior when reading from a binary file. However, if you wish, you can make this behavior coherent._
    
    마지막으로 `get_next_line`은 바이너리 파일을 읽을 때 정의되지 않은 동작을 가진다고 생각하셔야 합니다. 그러나 여러분이 원한다면 이러한 동작을 논리적으로 구현하셔도 됩니다.

- Gloval Variable : forbidden
- lseek : forbidden - file reading must be done only once.
- `-D BUFFER_SIZE` 옵션  없이도  작동해야 함. > 미지정시 기본 값필요함
- 바이너리 파일 읽을 경우 행위 미지정
- 
## 참고사항
[[variable]]
### static variable
자동 변수는 콜 스택서 할당/ 해제되지만, 정적 변수는 힙 메모리에 저장
따로 초기화하지 않을 경우 0
둘다 프로그램 런타임 동안 유지되지만 
전역변수는 파일 밖에서도 선언 후 사용 가능
정적변수는 파일 안에서만 사용 가능

## 보너스
- 정적변수 1개만 선언
- 여러 개의 파일 디스크립터 관리하기


아이디어 정리
- 정적 구조체를 선언, 정적 구조체 안에는 라인, 이 라인이 나갔는지, 안 나갔는지 포함
	- 첫번째를 정적 선언하고 나머지를 말록할 경우, 나머지는 

chk_head
- static pointer head 선언 
- 이후 fd에 따라 line head를 찾아서 해당 line 반환
- 없을 경우 init, 오류시 할당 해제 후 말록 반환

	init_head
	- pointer head가 없을 경우 
	- pointer head, head, tail, head->node 생성
	- head->fd = fd 초기화
	- ==line->num = 0 초기화== 아직 미정
	

free_all(pointer head)
- 현재까지 생성된 모든 것을 반환

## pesudo code
정적 변수 : hhead (파일 디스크립터를 포함하는 리스트) 
hhead 
	head : fd 별 열어둔 파일 디스크립터를 저장.
		fd
		next(head)
		node : 파일 디스크립터에서 읽어낸 라인을 저장하는 리스트 노드.
			line : 읽어낸 라인
			num(check eof & out) : eof 감지시 -1, 내보냄 0, 안내보냄 1. 미완 2. 초기화 2.
			next(node)

함수 실행 시 fd를 받는다.
	이미 열린 파일 디스크립터인지 확인한다.
			hhead가 없을 경우 새로 생성한다.
		열려 있을 경우 : 해당 line을 찾아 반환한다
		닫혀 있을 경우 : 파일 디스크립터를 새로 열고, hhead에 저장한다. 저장된 새로운 head를 반환한다.
	파일 디스크립터 노드가 미생성시(말록 할당 실패): 널리턴
	새로운 라인이 있는지 탐색 : head 받아서 돌리면서 확인
		head 내 node를 순환, node->num 확인
		get_last_node : 마지막 노드 반환
		if
			num : -1 : eof, return stop
				close fd
				return 0
			num : 0  *eof는 아니지만 읽은 건 다 보냈음* 
				make_newline
					while (read_num == buffer)
							if  buf contains n : 
								get_newline & return newline
									node->num = 1
									node->line = newline
									node-> next = 0 
							else
								new node : realloc and alloc buf to newline
					while end : read_num buffer가 다르므로 eof 도달
						get_newline & return newline
							node->num = 0
							node->line = newline
							node-> next = 0 
			num : 2 : get newline, continue
				read add_line : num == 2 || 
					read - buffer size만큼, while - \n appears
					make_newline
			num == 1 
				: return node->line