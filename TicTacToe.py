print('Welcom to Tic Tac Toe!')

x = 'X'
o = 'O'
e = ' '

board = [e,e,e,e,e,e,e,e,e]

def checkForInput(n):
    return n>=1 and n<=9 and board[n-1] == e

def printBoard():
    print('_{}_|_{}_|_{}_'.format(board[0],board[1],board[2]))
    print('_{}_|_{}_|_{}_'.format(board[3],board[4],board[5]))
    print(' {} | {} | {} '.format(board[6],board[7],board[8]))
    

def checkWin():
    for i in range(0,7,3):
        if(board[i] == board[i+1] and board[i+1] == board[i+2]):
            return board[i]
    for i in [0,1,2]:
        if(board[i] == board[i+3] and board[i+3] == board[i+6]):
            return board[i]
    if(board[0] == board[4] and board[4] == board[8]):
        return board[0]
    if(board[2] == board[4] and board[4] == board[8]):
        return board[2]
    return e

def gameLoop():
    turn = 1
    player1 = input('Player 1, Enter your option X or O: ')
    gameWon = True
    if(player1 == x):
        print('Player 1 will go first!')
        option1 = x
        option2 = o
    else:
        print('Player 2 will go first!')
        turn *=-1
        option2 = x
        option1 = o
        option1 = None
        option2 = None
        gameWon = False
    while(1):
        printBoard()
        if(turn == 1):
            place = int(input('Player 1: Enter any num (1-9)'))
            if(checkForInput):
                board[place-1] = option1            
        else:
            place = int(input('Player 2: Enter any num (1-9)'))
            if(checkForInput):
                board[place-1] = option2
        winner = checkWin()
        if(winner!=e):
            gameWon = True
            if(winner == option1):
                print('Congrats to Player 1')
            else:
                print('Congrats to Player 2')
        if(gameWon == True):
            playAgain = ('Do you want to play again (y\n)')
            if(playAgain == 'y'):
                gameLoop()
        turn *= -1

gameLoop()