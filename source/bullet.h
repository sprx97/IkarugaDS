#ifndef BULLET_H //header guard
#define BULLET_H
class bullet {
	public:
		bullet(int xpos, int ypos, int xvel, int yvel, bool c);
		int x;
		int y;
		int dx;
		int dy;
		bool color;

		void update();
		void remove();
};
#endif //BULLET_H header guard
