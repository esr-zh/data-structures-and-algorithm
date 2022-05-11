#ifndef SELECTIONALGORITHM_H
#define SELECTIONALGORITHM_H


class SelectionAlgorithm {
public:
	virtual int select();
	SelectionAlgorithm(int);

protected:
	int k;
};

#endif 