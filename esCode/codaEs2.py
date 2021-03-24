#Es: Inverti coda usando le pile

def push(stack,element):
    stack.append(element)

def pop(stack):
    return stack.pop()

def dequeue(queue):
    return queue.pop(0)

def enqueue(queue, element):
    queue.append(element)

def main():
    queue = []
    stack = []
    while True:
        element = int(input("Inserisci un valore: "))
        enqueue(queue,element)
        
        risposta = input("Inserisci 'n' se vuoi uscire. || Inserisci 's' per continuare: ")
        if risposta == "n" or risposta == "N":
            break

    for _ in range(len(queue)):
        push(stack, dequeue(queue))

    for _ in range(len(stack)):
        enqueue(queue, pop(stack))
    
    for _ in range(len(queue)):
        print(dequeue(queue))

if __name__ == "__main__":
    main()