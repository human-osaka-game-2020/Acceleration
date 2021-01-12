#ifndef GAME_SCENE_H
#define GAME_SCENE_H

class GameScene
{
public:
	GameScene();
	~GameScene();

public:
	void Draw();
	void Exec();

private:
	bool finishedAnimation[number];
	int randPos_x;
	int randPos_y;
};

#endif // !GAME_SCENE_H
