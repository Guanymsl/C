Matrix::Matrix(int _h, int _w)
{
	mat = new int*[_h];

    for(int i=0; i<_h; i++) mat[i] = new int[_w];

    for(int i=0; i<_h; i++){

        for(int j=0; j<_w; j++) mat[i][j] = 0;

    }

    w = _w;
    h = _h;

}

Matrix::~Matrix()
{

    for(int i=0; i<h; i++) delete [](mat[i]);
    delete []mat;

}