#ifndef SHIP_H //header guard
#define SHIP_H
class ship {
	public:
		ship();
		int x;
		int y;
		int shieldsize;
		bool isWhite;
		bool shieldshrinking;
		bool shieldgrowing;

		void update();
		void switchColor();
};
#endif //SHIP_H header guard
