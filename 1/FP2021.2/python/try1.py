from math import sqrt
def main():
    try:
        num = float(input())
        print(sqrt(num))

    except Exception as e:
        print(f'ocorreu um erro: {e}')
        main()

if __name__ == '__main__':
    main()