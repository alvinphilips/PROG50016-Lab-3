#pragma once

#ifndef IRENDERABLE_H
#define IRENDERABLE_H

class IRenderable {
	friend class RenderSystem;
protected:
	IRenderable() = default;
	virtual ~IRenderable() = default;
	virtual void Render() = 0;
};

#endif