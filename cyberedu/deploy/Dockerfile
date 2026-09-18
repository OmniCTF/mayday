FROM gcc:12 AS builder

WORKDIR /src
COPY chall.c .

RUN gcc chall.c -o chall -fno-stack-protector -no-pie -z execstack -O0

FROM debian:bookworm-slim

RUN apt-get update && apt-get install -y --no-install-recommends socat libc6 && rm -rf /var/lib/apt/lists/*

WORKDIR /home/ctf

COPY --from=builder /src/chall /home/ctf/chall
COPY flag.txt /home/ctf/flag.txt

RUN chown root:root /home/ctf/flag.txt && chmod 444 /home/ctf/flag.txt
RUN useradd -m ctf && chown -R ctf:ctf /home/ctf
USER ctf

EXPOSE 6767

CMD ["socat", "TCP-LISTEN:6767,reuseaddr,fork", "EXEC:/home/ctf/chall"]