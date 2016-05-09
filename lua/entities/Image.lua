local Image = {}

function Image.new(file, pos, scale)
    local self = {}
    self.Renderable = {
        zValue = -1
    }
    self.Graphical = {
        texture = file
    }
    self.Spatial = {
        position = pos
    }
    return self
end

return Image