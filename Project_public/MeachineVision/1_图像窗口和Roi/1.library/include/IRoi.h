#ifndef INTERFACE_ROI_H
#define INTERFACE_ROI_H

#include <QGraphicsItem>
#include <unordered_map>
#include <functional>
#include <any>
#include "RoiParameter.h"

namespace MVRoi {

/*
* @brief 定义dll的链接符号
*/
#ifdef ROI_DLL
#define ROI_API __declspec(dllexport)
#else
#define ROI_API __declspec(dllimport)
#endif

	/*
	* @brief Roi接口类
	*/
	struct ROI_API IRoi : public QGraphicsItemGroup
	{
		/*
		* @brief 获得当前ROI参数
		* @return 当前ROI参数,具体定义见RoiType枚举对应的Roi数据结构体
		*/
		virtual std::any GetParams() = 0;
	};

	//roi构建工厂与接口
	class ROI_API RoiFactory
	{
	public:
		/*
		* @brief 初始化Roi工厂，必须在create之前调用，注意调用Init之后所有类型roi都会被注册
		*/
		static void Init();
		/*
		* @brief 创建具体的Roi实例
		* @param type roi类型
		* @return 创建的roi实例指针，是一个std::shared_ptr<IRoi>
		*/
		static std::shared_ptr<MVRoi::IRoi> Create(const RoiType& type);
	private:
		using CreateFunc = std::function<std::shared_ptr<IRoi>()>; //Roi创建函数的指针别名
		/*
		*@brief 获得注册的所有roi构造映射
		*/
		static std::unordered_map<RoiType, CreateFunc>& GetRegistry();
		/*
		*@brief 注册的roi构造映射
		*/
		static void RegisterType(const RoiType& type, CreateFunc func);
	};

}

#endif
