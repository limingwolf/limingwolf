#ifndef INTERFACE_ROI_H
#define INTERFACE_ROI_H

#include <QGraphicsItem>
#include <unordered_map>
#include <functional>
#include <any>
#include "RoiParameter.h"

namespace MVRoi {

/*
* @brief ����dll�����ӷ���
*/
#ifdef ROI_DLL
#define ROI_API __declspec(dllexport)
#else
#define ROI_API __declspec(dllimport)
#endif

	/*
	* @brief Roi�ӿ���
	*/
	struct ROI_API IRoi : public QGraphicsItemGroup
	{
		/*
		* @brief ��õ�ǰROI����
		* @return ��ǰROI����,���嶨���RoiTypeö�ٶ�Ӧ��Roi���ݽṹ��
		*/
		virtual std::any GetParams() = 0;
	};

	//roi����������ӿ�
	class ROI_API RoiFactory
	{
	public:
		/*
		* @brief ��ʼ��Roi������������create֮ǰ���ã�ע�����Init֮����������roi���ᱻע��
		*/
		static void Init();
		/*
		* @brief ���������Roiʵ��
		* @param type roi����
		* @return ������roiʵ��ָ�룬��һ��std::shared_ptr<IRoi>
		*/
		static std::shared_ptr<MVRoi::IRoi> Create(const RoiType& type);
	private:
		using CreateFunc = std::function<std::shared_ptr<IRoi>()>; //Roi����������ָ�����
		/*
		*@brief ���ע�������roi����ӳ��
		*/
		static std::unordered_map<RoiType, CreateFunc>& GetRegistry();
		/*
		*@brief ע���roi����ӳ��
		*/
		static void RegisterType(const RoiType& type, CreateFunc func);
	};

}

#endif
