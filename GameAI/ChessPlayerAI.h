#pragma once
#include "Chess\ChessPlayer.h"
#include "Texture2D.h"
#include"Chess\ChessOpenings.h"
#include "Chess\ChessMoveManager.h"
#include "GameScreenManager.h"
#include "ChessClosings.h"


class ChessPlayerAI :
	public ChessPlayer
{
public:
	ChessPlayerAI(SDL_Renderer* renderer, COLOUR colour, Board* board, vector<Vector2D>* highlights, Vector2D* selectedPiecePosition, Move* lastMove, int* searchDepth);
	~ChessPlayerAI();

	bool inOpeningStage;
	bool inClosingStage;
	int currentMoveNumber;

	int* searchDepth;

	Move bestMove;
	vector<Move> *bestmoves = new vector<Move>;

	//MiniMaxAlphaBeta
	Board bestMoveBoard;
	int AllTimeHigh;
	int AllTimeLow;

	Board createBoardFromMove(Board _board, Move _move);
	COLOUR futureWhoseMove;
	Board CalcBoardFitness(Board board);

	int MinimumAlphaBetaPruning(Board node, int depth, int parentHigh);
	int MaximumAlphaBetaPruning(Board node, int depth, int parentLow);

	void DebugOutput();
	bool TakeATurn(SDL_Event e);
	//bool MakeAMove(Vector2D boardPosition);
	void EndTurn();
	bool MakeAMove(Move _move);
	GAMESTATE PreTurn();

	//Virtual Methods that I need from chessPlayer.cpp
	//virtual GAMESTATE	PreTurn();
	//virtual bool		TakeATurn(SDL_Event e);
	//virtual void		EndTurn();
	//virtual bool MakeAMove(Vector2D boardPosition);

};

