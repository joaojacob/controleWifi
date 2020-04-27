import socket, configparser

config = configparser.ConfigParser()
config.read('conf.ini')

sock = socket.socket()

def inter():

    #host e port definidos no arquivo de configuração conf.ini
    host = config['CONF']['host']
    port=int(config['CONF']['port'])

    sock.connect((host, port))

def sendInt(mens):
    sock.send((mens).encode())

def closeInt():
    sock.close()


def mensW():
    msg = input()
    while msg != 'sair':
        sock.send(msg)
        msg = input()
    sock.close()