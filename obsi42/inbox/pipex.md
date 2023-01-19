> pipex 스터디 노션 링크

# 🌈 구현 형태
## Mendetory
`./pipex infile "ls -l" "wc -l" outfile`
./programname filename1 "cmd1" "cmd2" filename2
`< file1 cmd1 | cmd2 > file2`
위와 같이 작동
## Bonus
- cmd 여러 개일 때
- << , >> 지원
- 첫 매개변수가 here_doc일 때 확인

# 🌈 허용 함수
- open, close, read, write, malloc, free, perror, strerror, access, dup, dup2, execve, exit, fork, pipe, unlink, wait, waitpid 
- ft_printf and any equivalent YOU coded

한번 천천히 살펴보자
