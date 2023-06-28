#pragma once

#include "ppch.h"

#include "PEngine/Core.h"
#include "PEngine/Events/Event.h"

namespace PEngine
{
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "PEngine", unsigned int width = 1280, unsigned int height = 720)
			: Title(title), Width(width), Height(height)
		{
		}
	};

	class PEngine_API Window
	{
		public:
			using EventCallbackFunc = std::function<void(Event&)>;

			virtual ~Window() {}

			virtual void OnUpdate() = 0;

			virtual unsigned int GetWidth() const = 0;
			virtual unsigned int GetHeight() const = 0;

			virtual void SetEventCallback(const EventCallbackFunc& callback) = 0;
			virtual void SetVSync(bool enabled) = 0;
			virtual bool IsVSync() const = 0;

			static Window* Create(const WindowProps& props = WindowProps());
	};
}