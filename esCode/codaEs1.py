#Es: Carica numeri interi in una coda

def dequeue(queue):
    return queue.pop(0)

def enqueue(queue, element):
    queue.append(element)

def main():
    queue = []

    while True:
        element = int(input("Inserisci valore: "))
        enqueue(queue,element)

        risposta = input("Inserisci 'n' se vuoi uscire. || Inserisci 's' per continuare: ")
        if risposta == "n" or risposta == "N":
            break
    
    for _ in range(len(queue)):
        print(dequeue(queue))
        


if __name__ == "__main__":
    main()