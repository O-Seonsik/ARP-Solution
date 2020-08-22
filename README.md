# Hyper-Strong-IPS(킹왕짱 쎈 IPS)
## 4 BoB9th hackathon
### 개발 언어
- C++
### 도구
- Suricata
  - 룰을 통해 특정 유형의 패킷 차단
  - 크게 패킷을 TCP / UDP / HTTP / ICMP로 구분하여 공격 차단
    - TCP : TCP SYN Flooding, TCP FIN Scan, TCP Half(SYN) Open Scan, Xmas Scan, NULL Scan ...
    - UDP : UDP Port Scanning, UDP Flooding ...
    - HTTP : HTTP GET Flooding, XSS, SQL Injection, Slow HTTP POST Dos ...
    - ICMP : ICMP Redirection, ICMP Flooding, Ping of Death, Land Attack
    
### 제작방법
- 리눅스 LKM
- 커널 소켓 버퍼 이용
- 소켓 버퍼를 후킹

    - 
