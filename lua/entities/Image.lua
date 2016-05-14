local Image = {}

function Image.new(file, pos, scl, layer)
    local self = {}
    self.Renderable = {
        zValue = layer
    }
    self.Graphical = {
        texture = file,
        scale = scl
    }
    self.Spatial = {
        position = pos
    }
    return self
end

return Image