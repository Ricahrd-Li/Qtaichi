#pragma once
#include "figure.h"

namespace minidraw {
	class CScanLine
	{
	public:
		CScanLine(Figure* p_polygon);
		~CScanLine();

		void InitInfo();
		void FillPolygon();
		float GetRectArea(); // ��ð�������εľ��ε����
		
		int top, bottom, left, right, width, height;
		std::map<std::pair<int, int>, bool> mat_inside;

	private:

		void BuildET();
		void UpdateAET(int height);
		void CalcIntersects(int height);

		struct CEdge
		{
			int ymax;
			double dx;
			double x;

			inline bool operator<(const CEdge& e2) const
			{
				return x < e2.x;
			}
		};
		Figure* p_polygon;

		std::vector<std::list<CEdge>>	edge_table;				//�߱�
		std::list<CEdge>				active_edge_table;		//���Ա߱�
		std::vector<double>				intersects;				//����

	};
};
