#pragma once
/*
* 事件基类
*/
#include "sunpch.h"
#include "SunEngine/Core/Base.h"
namespace SunEngine {

	/// <summary>
	/// 事件类型
	/// </summary>
	enum class EventType {
		None = 0,
		// 窗口事件
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		// 应用事件
		AppTick, AppUpdate, AppRender,
		// 键盘事件
		KeyPressed, KeyReleased,
		// 鼠标事件
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	/// <summary>
	/// 事件分类 使用位掩码
	/// </summary>
	enum EventCategory {
		None = 0,
		EventCategoryApplication		= BIT(0),
		EventCategoryInput				= BIT(1),
		EventCategoryKeyboard			= BIT(2),
		EventCategoryMouse				= BIT(3),
		EventCategoryMouseButton		= BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType(){return EventType::##type;}\
							   virtual EventType GetEventType() const override {return GetStaticType();}\
							   virtual const char* GetName() const override {return #type;}	

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override {return category;}

	/// <summary>
	/// 事件基类
	/// </summary>
	class Event {
		friend class EventDispatcher;
	public:
		virtual ~Event() = default;
		virtual EventType GetEventType()	const = 0;
		virtual const char* GetName()		const = 0;
		virtual int GetCategoryFlags()		const = 0;
		virtual std::string ToString()		const { return GetName(); }

		inline bool IsInCategory(EventCategory category) {
			return GetCategoryFlags() & category;
		}

		inline bool Handled() const { return m_Handled;}
	protected:
		bool m_Handled = false;
	};

	/// <summary>
	/// 事件调度器
	/// </summary>
	class EventDispatcher {
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event) :m_Event(event) {

		}

		template<typename T>
		bool Dispatch(EventFn<T> func) {
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.m_Handled |= func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e) {
		return os << e.ToString();
	}
}